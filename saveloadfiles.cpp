#include "saveloadfiles.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

SaveLoadFiles::SaveLoadFiles(DrawWidget *parent)
{
    drawWidget = parent;
    registerSaveText(QMetaType::Int, [] (const QVariant p){
        return p.toString();
    });
    registerSaveText(QMetaType::Float, [] (const QVariant p){
        return p.toString();
    });
    registerSaveText(QMetaType::QString, [] (const QVariant p){
        return p.toString();
    });
    registerSaveText(QMetaType::QPointF, [] (const QVariant p){
        QPointF point = p.value<QPointF>();
        return QString("%1,%2").arg(point.x()).arg(point.y());
    });
    registerSaveText(QMetaType::QPen, [] (const QVariant p){
        QPen pen = p.value<QPen>();
        return pen.color().name();
    });
    registerSaveText(QMetaType::QBrush, [] (const QVariant p){
        QBrush brush = p.value<QBrush>();
        return brush.color().name();
    });


    registerLoadText(QMetaType::Int, [] (const QString p){
        return QVariant(p);
    });
    registerLoadText(QMetaType::Float, [] (const QString p){
        return QVariant(p);
    });
    registerLoadText(QMetaType::QString, [] (const QString p){
        return QVariant(p);
    });
    registerLoadText(QMetaType::QPointF, [] (const QString p){
        QList<QString> parts = p.split(",");
        if (parts.length() != 2) return QVariant();
        QPointF point(parts[0].toInt(), parts[1].toInt());
        return QVariant(point);
    });
    registerLoadText(QMetaType::QPen, [] (const QString p){
        QColor color(p);
        QPen pen(color);
        return QVariant(pen);
    });
    registerLoadText(QMetaType::QBrush, [] (const QString p){
        QColor color(p);
        QBrush brush(color);
        return QVariant(brush);
    });
}

int SaveLoadFiles::getSaveFormat()
{
    return m_saveFormat;
}

void SaveLoadFiles::setSaveFormat(int index)
{
    m_saveFormat = index;
}

void SaveLoadFiles::getSaveData(QString fileName)
{
    QList objects = drawWidget->getObjects();
    QFile file(fileName);
    if (m_saveFormat == saveFormat::binary){
        if (file.open(QIODevice::WriteOnly)) {
            QDataStream steam(&file);
            steam << objects;
            file.close();
        }
    } else if (m_saveFormat == saveFormat::text){
        if (file.open(QIODevice::WriteOnly)) {
            for (auto item: objects) {
                QString text = "{ \n";
                for (const auto &[key, value]: item.asKeyValueRange()) {
                    text += QString("%1").arg(value.typeId());
                    text += " : " + key + " : ";
                    text += mapSaveText[value.typeId()](value);
                    text += "\n";
                }
                text += " } \n";
                file.write(text.toUtf8());
                qDebug() << text;
            }
            file.close();
        }
    }
}

void SaveLoadFiles::setObjectData(QString fileName)
{
    QFile file(fileName);
    if (m_saveFormat == saveFormat::binary){
        drawWidget->clear();
        QList<params> objects;
        if (file.open(QIODevice::ReadOnly)){
            QDataStream steam(&file);
            steam >> objects;
            file.close();
        }
        for (const auto& objParams: objects) {
            drawWidget->addShape(objParams["mode"].value<QString>(), objParams);
        }
    } else if (m_saveFormat == saveFormat::text){
        drawWidget->clear();
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
        QTextStream steam(&file);
        params obj;
        while (!steam.atEnd()) {
            QString line = steam.readLine().trimmed();

            if (line == "{"){

            } else if (line == "}"){
                drawWidget->addShape(obj["mode"].value<QString>(), obj);
            } else {
                QList<QString> parts = line.split(" : ");
                if (parts.length() != 3) {
                    alertLoad();
                    return;
                }
                int id = parts[0].toInt();
                QString key = parts[1];
                QVariant p = mapLoadText[id](parts[2]);
                obj[key] = p;
            }
        }
        file.close();
    }
}

void SaveLoadFiles::registerSaveText(int id, saveText func)
{
    mapSaveText[id] = func;
}

void SaveLoadFiles::registerLoadText(int id, loadText func)
{
    mapLoadText[id] = func;
}

void SaveLoadFiles::alertLoad(QString str)
{
    drawWidget->clear();
    QMessageBox::warning(drawWidget, "Ошибка данных", str);
}
