#ifndef CAR_H
#define CAR_H

#include "moving.h"
#include <QPointF>

class Car: public Move
{
    Q_OBJECT
public:
    Car(QPointF point, QBrush brush = QBrush(Qt::green), float speed = 0.1);
    void draw(QPainter *painter) const override;
    params getSerializeMap() const override;
    QString getType() const override {return "Car";};

private:
    QBrush m_brush;
};

#endif // CAR_H
