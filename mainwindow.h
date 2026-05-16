#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <saveloadfiles.h>
#include <QStandardPaths>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    void extracted(QStringList &names);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PBclear_clicked();

    void on_PBColor_clicked();

    void on_PBSave_clicked();

    void on_PBLoad_clicked();

    void on_CBMovement_checkStateChanged(const Qt::CheckState &arg1);

    void on_CBShape_currentIndexChanged(int index);

    void on_PBPlugin_clicked();

    void on_CBSaveFormat_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QColor currentColor = Qt::green;
    QFileDialog fileDialogLoad = QFileDialog(this);
    QFileDialog fileDialogSave = QFileDialog(this);
    SaveLoadFiles saveLoadFiles;
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QStringList shapeNames;
};
#endif // MAINWINDOW_H
