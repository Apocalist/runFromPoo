#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "Timer.h"
#include "Vec2.h"

class Dude {

public:

	Dude(float in_x, float in_y)
	{
		pos.x = in_x;
		pos.y = in_y;

	}

	void MoveDude(const Keyboard& kbd,Timer& time);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	Vec2 GetPos() const;
	int GetWidth() const;
	int GetHeight() const;

private:

	Vec2 pos;
	Vec2 trans;
	float speedRate = 0.1f;
	float speed = 3.0f;
	static constexpr int width = 20;
	static constexpr int height = 20;

};
