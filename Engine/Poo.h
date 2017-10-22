#pragma once
#include "Graphics.h"
#include "Dude.h"
#include <random>
#include "Timer.h"

class Poo
{
public:

	void RandPos(float(in_x), float(in_y), float  in_x_dir, float in_y_dir,Timer& time);
	void Update(Timer& time);
	void Draw(Graphics& gfx);
	void isColliding(const Dude& dude);
	bool IsEaten() const;
	float GetWidth() const;
	float GetHeight() const;
	void Reset();

private:


	Vec2 pos;
	Vec2 dir;
	bool isEaten = false;
	static constexpr float width = 25;
	static constexpr float height = 25;
};