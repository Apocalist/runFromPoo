#pragma once
#include "Graphics.h"
#include "Dude.h"
#include <random>

class Poo
{
public:

	void RandPos(int in_x, int in_y, int  in_x_dir, int in_y_dir);
	void Update();
	void Draw(Graphics& gfx);
	void isColliding(const Dude& dude);
	bool IsEaten() const;
	int GetWidth() const;
	int GetHeight() const;
	void Reset();

private:

	int x;
	int y;
	int x_dir;
	int y_dir;
	bool isEaten = false;
	static constexpr int width = 25;
	static constexpr int height = 25;
};