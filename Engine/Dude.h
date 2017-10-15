#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "Timer.h"

class Dude {

public:

	Dude(float in_x, float in_y)
	{
		x = in_x;
		y = in_y;

	}

	void MoveDude(const Keyboard& kbd, class Timer time);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	float GetX() const;
	float GetY() const;
	int GetWidth() const;
	int GetHeight() const;

private:

	float x;
	float y;
	float x_trans;
	float y_trans;
	float speedRate = 0.1f;
	float speed = 3.0f;
	static constexpr int width = 20;
	static constexpr int height = 20;

};
