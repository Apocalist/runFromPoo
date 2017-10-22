#pragma once

class Vec2 {

public:

	Vec2() =  default;
	Vec2(float in_x, float in_y);

	float GetLength();
	float GetLengthSqr();

	Vec2 operator + (const Vec2& v) const;
	Vec2& operator += (const Vec2& v);
	Vec2 operator - (const Vec2& v) const;
	Vec2& operator -= (const Vec2& v);
	Vec2 operator * (float a) const;
	Vec2& operator *= (float a);

public:
	float x;
	float y;


};