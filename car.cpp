#include "car.h"
#include <QPainterPath>
#include "factory.h"

static shapeRegister registerModule("Car", [](const params& p){
    return std::make_unique<Car>(
        p["end"].value<QPointF>(),
        p["brush"].value<QBrush>()
        );
});

Car::Car(QPointF point, QBrush brush, float speed):
    Move(point.x(), point.y(), speed), m_brush(brush) {}

void Car::draw(QPainter *painter) const
{
    painter->save();
    painter->translate(m_x-20, m_y-20);

    // КУЗОВ (главный цвет)
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(m_brush);

    QPainterPath body;
    body.moveTo(5, 40);
    body.lineTo(20, 25);
    body.lineTo(65, 25);
    body.lineTo(85, 40);
    body.lineTo(95, 40);
    body.lineTo(95, 50);
    body.lineTo(5, 50);
    body.closeSubpath();

    painter->drawPath(body);

    // ОКНА
    painter->setBrush(QColor(180, 220, 255));
    painter->drawRect(25, 28, 18, 12);
    painter->drawRect(45, 28, 18, 12);

    // ФАРЫ
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(92, 42, 5, 5);

    painter->setBrush(Qt::red);
    painter->drawEllipse(3, 42, 5, 5);

    // КОЛЁСА
    painter->setBrush(Qt::black);
    painter->drawEllipse(20, 45, 18, 18);
    painter->drawEllipse(65, 45, 18, 18);

    // Диски
    painter->setBrush(Qt::gray);
    painter->drawEllipse(25, 50, 8, 8);
    painter->drawEllipse(70, 50, 8, 8);

    // Дверная линия
    painter->setPen(QPen(Qt::black, 1));
    painter->drawLine(44, 25, 44, 50);

    painter->restore();
}

params Car::getSerializeMap() const
{
    params p;
    p["mode"] = "Car";
    p["end"] = QPointF(m_x, m_y);
    p["brush"] = m_brush;
    p["speed"] = m_speed;
    return p;
}
