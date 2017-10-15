#include "Box.h"
#include "Dude.h"

bool Box::BoxCollide(const Dude& dude)
{
	return  x + width >= dude.GetX() &&
			x <= dude.GetX() + dude.GetWidth() &&
			y + height >= dude.GetY() &&
			y <= dude.GetY() + dude.GetHeight();
}


void Box::ShufflePos(int in_x, int in_y, bool collided)
{
	if (collided) {

		x = in_x;
		y = in_y;
	}
}

void Box::RandPos(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Box::Draw(Graphics& gfx)
{
	for (int iX = x; iX < width + x; iX++) {
		for (int iY = y; iY < height + y; iY++) {
			gfx.PutPixel(iX, iY, 200, 200, 200);
		}
	}
}


int Box::getX()
{
	return x;
}

int Box::getY()
{
	return y;
}

int Box::getWidth()
{
	return width;
}

int Box::getHeight()
{
	return height;
}
