#include "factory.h"
#include <QDebug>

Factory::Factory() {}
// factory.cpp
extern "C" __declspec(dllexport) void force_lib_creation() {}

Factory &Factory::getFactory()
{
    static Factory factory;
    return factory;
}

void Factory::registerClass(const QString& name, creator func)
{
    factoryRegistr[name] = func;
}

std::unique_ptr<shape> Factory::createChape(const QString &name, const params &p)
{
    if (factoryRegistr[name]){
        return factoryRegistr[name](p);
    } else {
        qDebug() << "in factory dont find name:" << name;
        return NULL;
    }
}

QStringList Factory::getRegisterName()
{
    return factoryRegistr.keys();
}
