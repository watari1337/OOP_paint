#ifndef MOVING_H
#define MOVING_H

#include <shape.h>
#include <QtCore/qglobal.h>

#if defined(MOVE_LIBRARY)
#define MOVE_EXPORT Q_DECL_EXPORT
#else
#define MOVE_EXPORT Q_DECL_IMPORT
#endif

class MOVE_EXPORT Move: public shape
{
    Q_OBJECT
public:
    Move(float x = 0, float y = 0, float speed = 0.1);
    void moveObject(int time);

protected:
    float m_x, m_y, m_speed;
};

#endif // MOVING_H
