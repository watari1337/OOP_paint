#include "rectangle.h"
#include "factory.h"

static shapeRegister registerModule("Rectangle", [](const params& p){
    return std::make_unique<Rectangle>(
        QRectF(p["start"].value<QPointF>(), p["end"].value<QPointF>()),
        p["pen"].value<QPen>(),
        p["brush"].value<QBrush>()
        );
});

Rectangle::Rectangle(QRectF rect, QPen pen, QBrush brush)
    : m_rect(rect), m_pen(pen), m_brush(brush) {}

void Rectangle::draw(QPainter *painter) const
{
    painter->setPen(m_pen);
    painter->setBrush(m_brush);
    painter->drawRect(m_rect);
}

params Rectangle::getSerializeMap() const
{
    params p;
    p["mode"] = "Rectangle";
    p["start"] = m_rect.topLeft();
    p["end"] = m_rect.bottomRight();
    p["brush"] = m_brush;
    p["pen"] = m_pen;
    return p;
}

