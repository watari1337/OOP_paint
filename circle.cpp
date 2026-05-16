#include "circle.h"
#include "factory.h"

static shapeRegister registerModule("Circle", [](const params& p){
    return std::make_unique<Circle>(p);
});

Circle::Circle(const params& p)
{
    m_brush = p["brush"].value<QBrush>();
    m_pen = p["pen"].value<QPen>();
    m_rect = QRectF(p["start"].value<QPointF>(), p["end"].value<QPointF>());
}

void Circle::draw(QPainter *painter) const
{
    painter->setBrush(m_brush);
    painter->setPen(m_pen);
    painter->drawEllipse(m_rect);
}

params Circle::getSerializeMap() const
{
    params p;
    p["mode"] = "Circle";
    p["start"] = m_rect.topLeft();
    p["end"] = m_rect.bottomRight();
    p["brush"] = m_brush;
    p["pen"] = m_pen;
    return p;
}
