#ifndef __POINT_H__

#define __POINT_H__

class Point
{
protected:
	unsigned int _pointX;
	unsigned int _pointY;

public:
	Point(unsigned int x = 0, unsigned int y = 0);

	//getters
	unsigned int getPointY() const;
	unsigned int getPointX() const;

	//setters
	void setX(unsigned int x);
	void setY(unsigned int y);

	bool operator==(Point& other) const;
	bool operator==(const Point& other) const;
	Point operator+(Point& other) const;
	Point& operator+=(Point& other);
	Point operator-(Point& other) const;
	Point& operator-=(Point& other);
	Point& operator++(void);
	Point& operator--(void);

};

#endif // !__POINT_H__
