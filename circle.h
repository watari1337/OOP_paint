#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public shape
{
    Q_OBJECT
public:
    Circle(const params& p);
    void draw(QPainter *painter) const override;
    params getSerializeMap() const override;
    QString getType() const override {return "Circle";};

private:
    QRectF m_rect;
    QPen m_pen;
    QBrush m_brush;
};

#endif // CIRCLE_H
