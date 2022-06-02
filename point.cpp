#include "point.h"
#include <QPainter>
Point::Point(float x,float y, int size,int thickness,bool isdragg): x(x),y(y),size(size),thickness(thickness),isdragg(isdragg){}
float Point::getX() const
{
    return x;
}

void Point::setX(float x)
{
    this->x = x;
}

float Point::getY() const
{
    return y;
}

void Point::setY(float y)
{
    this->y = y;
}

bool Point::validate()
{
    return (x > 0 && y > 0);
}

int Point::getThickness() const
{
    return thickness;
}

void Point::setThickness(int thickness)
{
    this->thickness = thickness;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int size)
{
    this->size = size;
}

float Point::distance2(const QPoint &point)
{
     float xQuad = ((point.x() - x) * (point.x() - x));
     float yQuad = ((point.y() - x) * (point.y() - y));
     return (xQuad + yQuad);
}

bool Point::getisdragg() const
{
    return isdragg;
}

void Point::setisdragg(bool isdragg)
{
    this->isdragg = isdragg;
}


     ;
void Point::draw(QPainter *painter)
{
    int size_1 = size / 2;
    QPen pen;
    pen.setWidth(thickness);
    painter->setPen(pen);
    painter->drawLine(x - size_1,y,x + size_1,y);
    painter->drawLine(x,y - size_1 ,x,y + size_1);
}

void Point::connectPoints(QPainter *painter,Point *point)
{
    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawLine(point->x,point->y,x,y);
}
