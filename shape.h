#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPainter>
#include <QPointF>
#include <QPen>
#include <QBrush>
#include <QMap>
#include <QVariant>
#include <QtPlugin>

//using param = std::variant<QRect, QPointF, QBrush, QPen, int, float>;
using params = QMap<QString, QVariant>;

class shape: public QObject
{

public:
    virtual ~shape() {};
    virtual void draw(QPainter *painter) const = 0;
    virtual params getSerializeMap() const = 0;
    virtual QString getType() const = 0;
};

using creator = std::function< std::unique_ptr<shape>( const params&)>;

Q_DECLARE_INTERFACE(shape, "watari.oop/1.0")

#endif // SHAPE_H
