#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QPen>
#include <QRectF>

class Rectangle: public shape
{
    Q_OBJECT
public:
    Rectangle(QRectF rect, QPen pen = QPen(Qt::red, 1), QBrush brush = QBrush(Qt::green));

    void draw(QPainter *painter) const override;
    params getSerializeMap() const override;
    QString getType() const override {return "Rectangle";};
private:
    QRectF m_rect;
    QPen m_pen;
    QBrush m_brush;
};

#endif // RECTANGLE_H
