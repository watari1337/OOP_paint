#include "drawwidget.h"
#include "circle.h"
#include "rectangle.h"
#include "car.h"
#include "helicopter.h"
#include "moving.h"
#include "factory.h"
#include <QTimer>
#include <QFile>
#include <QDataStream>
#include <QList>
#include <QPluginLoader>
#include <QDir>
#include <QStringList>

DrawWidget::DrawWidget(QWidget *parent)
    : QWidget{parent}
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DrawWidget::updateCard);
    timer->start(16);
    m_params["pen"] = QPen(Qt::black);
    m_params["brush"] = QBrush(Qt::green);
    loadPlagins();
}

void DrawWidget::addShape(QString str, params param)
{
    std::unique_ptr<shape> shape = Factory::getFactory().createChape(str, param);
    shapes.push_back(std::move(shape));
    update();
}

void DrawWidget::setDrawMode(QString mode)
{
    m_mode = mode;
}

QList<params> DrawWidget::getObjects()
{
    QList<params> objects;
    for (const auto& shape: shapes) {
        objects.push_back( shape->getSerializeMap());
    }
    return objects;
}

void DrawWidget::setColor(QColor color)
{
    m_params["pen"] = QPen(color);
    m_params["brush"] = QBrush(color);
    m_color = color;
}

void DrawWidget::clear()
{
    shapes.clear();
    update();
}

void DrawWidget::setCadrPlay(bool flag)
{
    isCardPlay = flag;
}

void DrawWidget::updateCard()
{
    if (isCardPlay){
        for (size_t i = 0; i < shapes.size(); ++i) {
            Move *object = dynamic_cast<Move*>(shapes[i].get());
            if (object) object->moveObject(16);
        }
        update();
    }
}

void DrawWidget::loadPlagins()
{
    allShapes.clear();
    //allShapes << new Circle();
    QStringList filter = {"*.dll"};
    QDir dirPlugins(qApp->applicationDirPath() + "/plugins");
    for (QString fileName: dirPlugins.entryList(filter, QDir::Files)){
        QPluginLoader loader(dirPlugins.absoluteFilePath(fileName));
        QObject* obj = loader.instance();
        if (obj){
            shape* objShape = qobject_cast<shape*>(obj);
            allShapes << objShape;
        } else {
            qDebug() << "Ошибка в файле:" << fileName;
            qDebug() << "Текст ошибки:" << loader.errorString();
        }
    }
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    for (size_t i = 0; i < shapes.size(); ++i) {
        shapes[i]->draw(&painter);
    }
    if (activeShape) {
        activeShape->draw(&painter);
    }
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_params["end"] = event->pos();
    activeShape = Factory::getFactory().createChape(m_mode, m_params);
    update();
}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    m_params["start"] = event->pos();
    m_params["end"] = event->pos();
    activeShape = Factory::getFactory().createChape(m_mode, m_params);
    update();
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (!activeShape) return;
    shapes.push_back(std::move(activeShape));
    update();
}
