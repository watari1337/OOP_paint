#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawwidget.h"
#include "QColorDialog"
#include <QByteArray>
#include <QDateTime>
#include "factory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LColor->setStyleSheet(
        "background-color: " + currentColor.name() + ";");
    for (int i = 0; i < shapeNames.length(); ++i) {
        ui->CBShape->addItem(shapeNames[i]);
    }
    saveLoadFiles = SaveLoadFiles(ui->draw);

    fileDialogLoad.setFileMode(QFileDialog::ExistingFile);
    fileDialogLoad.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialogLoad.setDirectory(desktopPath);

    fileDialogSave.setFileMode(QFileDialog::AnyFile);
    fileDialogSave.setAcceptMode(QFileDialog::AcceptSave);
    fileDialogSave.setDirectory(desktopPath);
    fileDialogSave.selectFile(desktopPath + "/save_file" + QDateTime().currentDateTime().toString("hh_mm_ss"));

    shapeNames = Factory::getFactory().getRegisterName();
    for (auto name : shapeNames) {
        ui->CBShape->addItem(name);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PBclear_clicked()
{
    ui->draw->clear();
}

void MainWindow::on_PBColor_clicked()
{
    QColor color = QColorDialog::getColor(currentColor, this);
    if (!color.isValid()) return;
    currentColor = color;
    ui->LColor->setStyleSheet(
        "background-color: " + currentColor.name() + ";");
    ui->draw->setColor(currentColor);
}


void MainWindow::on_PBSave_clicked()
{
    ui->draw->setCadrPlay(false);
    if (saveLoadFiles.getSaveFormat() == SaveLoadFiles::saveFormat::text){
        fileDialogSave.selectFile(desktopPath + "/save_file" + QDateTime().currentDateTime().toString("hh_mm_ss") + ".txt");
    } else if (saveLoadFiles.getSaveFormat() == SaveLoadFiles::saveFormat::text){
        fileDialogSave.selectFile(desktopPath + "/save_file" + QDateTime().currentDateTime().toString("hh_mm_ss"));
    }
    if (fileDialogSave.exec() == QFileDialog::Accepted){
        QString fileName = fileDialogSave.selectedFiles().first();
        saveLoadFiles.getSaveData(fileName);
    }
    ui->draw->setCadrPlay(true);
}


void MainWindow::on_PBLoad_clicked()
{
    ui->draw->setCadrPlay(false);
    if (fileDialogLoad.exec() == QFileDialog::Accepted){
        QString fileName = fileDialogLoad.selectedFiles().first();
        saveLoadFiles.setObjectData( fileName);
    }
    ui->draw->setCadrPlay(true);
}


void MainWindow::on_CBMovement_checkStateChanged(const Qt::CheckState &arg1)
{
    ui->draw->setCadrPlay(arg1);
}


void MainWindow::on_CBShape_currentIndexChanged(int index)
{
    if (index != -1){
        ui->draw->setDrawMode(shapeNames[index]);
    }
}


void MainWindow::on_PBPlugin_clicked()
{
    ui->CBShape->clear();
    ui->draw->loadPlagins();
    shapeNames = Factory::getFactory().getRegisterName();
    for (auto name : shapeNames) {
        ui->CBShape->addItem(name);
    }
}

void MainWindow::on_CBSaveFormat_currentIndexChanged(int index)
{
    saveLoadFiles.setSaveFormat(index);
}

