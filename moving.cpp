#include "moving.h"

Move::Move(float x, float y, float speed):
    m_x(x), m_y(y), m_speed(speed)
{

}

void Move::moveObject(int time)
{
    m_x += time * m_speed;
    if (m_x > 1800) m_x = -100;
}
