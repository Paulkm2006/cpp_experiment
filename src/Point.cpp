#include "Point.hpp"

adas::Point::Point(const int x, const int y) noexcept : x(x), y(y)
{
}

adas::Point::Point(const Point &rhs) noexcept : x(rhs.x), y(rhs.y)
{
}

adas::Point &adas::Point::operator=(const Point &rhs) noexcept
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	return *this;
}

adas::Point &adas::Point::operator+=(const Point &rhs) noexcept
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

adas::Point &adas::Point::operator-=(const Point &rhs) noexcept
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

int adas::Point::GetX() const noexcept
{
	return x;
}

int adas::Point::GetY() const noexcept
{
	return y;
}
