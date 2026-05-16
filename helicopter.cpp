#include "helicopter.h"
#include <QPainterPath>
#include "factory.h"

static shapeRegister registerModule("Helicopter", [](const params& p){
    return std::make_unique<Helicopter>(
        p["end"].value<QPointF>(),
        p["brush"].value<QBrush>()
        );
});

Helicopter::Helicopter(QPointF point, QBrush brush, float speed):
    Move(point.x(), point.y(), speed), m_brush(brush) {}

void Helicopter::draw(QPainter *painter) const
{
    painter->save();
    painter->translate(m_x + 70, m_y - 20);
    painter->scale(-1, 1);

    painter->setPen(QPen(Qt::black, 2));

    // ОСНОВНОЙ КОРПУС
    painter->setBrush(m_brush);

    QPainterPath body;
    body.moveTo(10, 40);
    body.lineTo(25, 25);
    body.lineTo(70, 25);
    body.lineTo(90, 35);
    body.lineTo(90, 45);
    body.lineTo(10, 45);
    body.closeSubpath();

    painter->drawPath(body);

    // КАБИНА
    painter->setBrush(QColor(180, 220, 255));
    painter->drawEllipse(20, 28, 25, 15);

    // ХВОСТ
    painter->setBrush(m_brush);
    QPainterPath tail;
    tail.moveTo(90, 38);
    tail.lineTo(130, 35);
    tail.lineTo(130, 42);
    tail.lineTo(90, 45);
    tail.closeSubpath();

    painter->drawPath(tail);

    // ХВОСТОВОЙ ВИНТ
    painter->setPen(QPen(Qt::darkGray, 2));
    painter->drawLine(130, 38, 140, 32);
    painter->drawLine(130, 38, 140, 44);

    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(128, 35, 6, 6);

    // ОСНОВНОЙ ВИНТ (мачта)
    painter->setPen(QPen(Qt::darkGray, 3));
    painter->drawLine(50, 25, 50, 15);

    // ЛОПАСТИ
    painter->setPen(QPen(Qt::darkGray, 4));
    painter->drawLine(10, 15, 90, 15);
    painter->drawLine(45, 12, 55, 18);

    // ЛЫЖИ
    painter->setPen(QPen(Qt::darkGray, 3));
    painter->drawLine(25, 50, 75, 50);

    painter->setPen(QPen(Qt::darkGray, 2));
    painter->drawLine(35, 45, 30, 50);
    painter->drawLine(65, 45, 70, 50);

    painter->restore();
}

params Helicopter::getSerializeMap() const
{
    params p;
    p["mode"] = "Helicopter";
    p["end"] = QPointF(m_x, m_y);
    p["brush"] = m_brush;
    p["speed"] = m_speed;
    return p;
}
