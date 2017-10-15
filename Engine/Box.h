#pragma once
#include "Dude.h"
#include "Graphics.h"


class Box {

public:
	
	bool BoxCollide(const Dude& dude);
	void ShufflePos(int in_x, int in_y, bool collided);
	void RandPos(int in_x, int in_y);
	void Draw(Graphics& gfx);
	int getX();
	int getY();
	int getWidth();
	int getHeight();

private:

	int x;
	int y;
	static constexpr int width = 20;
	static constexpr int height = 20;

};