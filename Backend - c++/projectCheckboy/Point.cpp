#include "Point.h"

/*
Constractur.
*/
Point::Point(unsigned int x, unsigned int y)
{
	this->_pointX = x;
	this->_pointY = y;
}

/*
Get Y value.
*/
unsigned int Point::getPointY() const
{
	return this->_pointY;
}

/*
Get X value.
*/
unsigned int Point::getPointX() const
{
	return this->_pointX;
}

/*
Set X value.
*/
void Point::setX(unsigned int x)
{
	this->_pointX = x;
}

/*
Set Y value.
*/
void Point::setY(unsigned int y)
{
	this->_pointY = y;
}

/*
Check if 2 points are equal.
*/
bool Point::operator==(Point& other) const
{
	return this->getPointX() == other.getPointX() && this->getPointY() && other.getPointY();
}

bool Point::operator==(const Point& other) const
{
	return this->getPointX() == other.getPointX() && this->getPointY() && other.getPointY();
}

/*
Operator+, add point to itself (values of X and Y), doesn't save changes.
*/
Point Point::operator+(Point& other) const
{
	return Point((this->getPointX() + other.getPointX()), (this->getPointY() + other.getPointY()));
}

/*
Operator +=, add point to itself (values of X and Y).
*/
Point& Point::operator+=(Point& other)
{
	this->_pointX += other.getPointX();
	this->_pointY += other.getPointY();
	return *this;
}

/*
Operator -, sub point from this point (values X and Y), doesn't save changes.
*/
Point Point::operator-(Point& other) const
{
	return Point((this->getPointX() - other.getPointX()),(this->getPointY() - other.getPointY()));
}

/*
Operator -=,  sub point from this point (values X and Y).
*/
Point& Point::operator-=(Point& other)
{
	this->_pointX -= other.getPointX();
	this->_pointY -= other.getPointY();
	return *this;
}

/*
Operator ++, add +1 to X and Y.
*/
Point& Point::operator++(void)
{
	this->_pointX++;
	this->_pointY++;
	return *this;
}

/*
Operator ++, sub 1 from X and Y.
*/
Point& Point::operator--(void)
{
	this->_pointX--;
	this->_pointY--;
	return *this;
}
