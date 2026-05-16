#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "moving.h"
#include <QPointF>

class Helicopter: public Move
{
    Q_OBJECT
public:
    Helicopter(QPointF point, QBrush brush = QBrush(Qt::green), float speed = 0.1);
    void draw(QPainter *painter) const override;
    params getSerializeMap() const override;
    QString getType() const override {return "Helicopter";};

private:
    QBrush m_brush;
};

#endif // HELICOPTER_H
