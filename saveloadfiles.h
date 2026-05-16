#ifndef SAVELOADFILES_H
#define SAVELOADFILES_H

#include<QString>
#include<drawwidget.h>

class SaveLoadFiles
{
public:
    enum saveFormat{
        binary = 0,
        text = 1
    };
    SaveLoadFiles(DrawWidget *parent = nullptr);
    int getSaveFormat();
    void setSaveFormat(int index);
    void getSaveData(QString fileName);
    void setObjectData(QString fileName);
private:
    using saveText = std::function< QString (const QVariant p)>;
    using loadText = std::function< QVariant (const QString p)>;
    void registerSaveText(int id, saveText func);
    void registerLoadText(int id, loadText func);
    QMap<int, saveText> mapSaveText;
    QMap<int, loadText> mapLoadText;
    void alertLoad(QString str = "Файл поврежден или имеет неверный формат!");
    int m_saveFormat = saveFormat::binary;
    DrawWidget *drawWidget;
};

#endif // SAVELOADFILES_H
