#pragma once
#include "Keyboard.h"
#include "Graphics.h"

class Dude {

public:

	Dude(float in_x, float in_y)
	{
		x = in_x;
		y = in_y;

	}

	void MoveDude(const Keyboard& kbd);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	float GetX() const;
	float GetY() const;
	int GetWidth() const;
	int GetHeight() const;

private:

	int time;

	float x;
	float y;
	float x_trans;
	float y_trans;
	float speedRate = 0.1;
	float speed = 3;
	static constexpr int width = 20;
	static constexpr int height = 20;

};
