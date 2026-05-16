#ifndef FACTORY_H
#define FACTORY_H

#include <shape.h>
#include <QStringList>
#include <QtCore/qglobal.h>

#if defined(FACTORY_LIBRARY)
#  define FACTORY_EXPORT Q_DECL_EXPORT  //даем функции другим
#else
#  define FACTORY_EXPORT Q_DECL_IMPORT  //берем функции извне
#endif

class FACTORY_EXPORT Factory
{
public:
    static Factory& getFactory();
    void registerClass(const QString& name, creator func);
    std::unique_ptr<shape> createChape(const QString& name, const params& p);
    QStringList getRegisterName();

    Factory(const Factory&) = delete;
    Factory& operator=(const Factory&) = delete;
private:
    Factory();
    QMap<QString, creator> factoryRegistr;
};

struct FACTORY_EXPORT shapeRegister{
    shapeRegister(const QString& type, creator func){
        Factory::getFactory().registerClass(type, func);
    }
};

#endif // FACTORY_H
