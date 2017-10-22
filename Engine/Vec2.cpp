#include "Vec2.h"
#include <cmath>

Vec2::Vec2(float in_x, float in_y):
	x(in_x),
	y(in_y)
{
}

float Vec2::GetLength()
{
	return sqrt(GetLengthSqr());
}

float Vec2::GetLengthSqr()
{
	return x*x + y*y ;
}

Vec2 Vec2::GetNormalized()
{
	const float len = GetLength();
	if (len != 0) {
		return *this * (1.0f / GetLength());
	}else{
		return *this;
	}
}

Vec2 Vec2::operator+(const Vec2 & v) const
{

	return Vec2(x + v.x , y + v.y );
}

Vec2 & Vec2::operator+=(const Vec2 & v)
{
	return *this = *this + v;
}

Vec2 Vec2::operator-(const Vec2 & v) const
{
	return Vec2(x - v.x, y - v.y);
}

Vec2 & Vec2::operator-=(const Vec2 & v)
{
	return *this = *this - v;
}

Vec2 Vec2::operator*(float a) const
{
	return Vec2( x * a, y * a);
}

Vec2 & Vec2::operator*=(float a)
{
	return *this = *this * a;
}
