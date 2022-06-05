#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point() {}
    Point(int x, int y);
    int getX();
    void setX(int newX);

    int getY();
    void setY(int newY);

protected:
    int x, y;
};

#endif // POINT_H
