#include "Dude.h"
#include <math.h>
#include "Graphics.h"
#include "Keyboard.h"


void Dude::MoveDude(const Keyboard& kbd,Timer& time) {

	//Move dude
	//And set limit to 1
	

	if (kbd.KeyIsPressed(VK_LEFT)) {
		if (trans.x >= -1) {
			trans.x -= speedRate;
		}
	}
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		if (trans.x <= 1) {
			trans.x += speedRate;
		}
	}

	if (kbd.KeyIsPressed(VK_UP)) {
		if (trans.y >= -1) {
			trans.y -= speedRate;
		}
	}
	if (kbd.KeyIsPressed(VK_DOWN)) {
		if (trans.y <= 1) {
			trans.y += speedRate;
		}
	}

	// Decelerate when key is not pressed

	if (!(kbd.KeyIsPressed(VK_LEFT)) && !(kbd.KeyIsPressed(VK_RIGHT))) {
		if ( trans.x < 0.005 && trans.x > -0.005) {
			trans.x = 0;
		}
		else {
			trans.x = (abs(trans.x) - speedRate) * (abs(trans.x) / trans.x); // absolute value of X * de curent direction of X (positive or negative)
		}
	}

	if (!(kbd.KeyIsPressed(VK_UP)) && !(kbd.KeyIsPressed(VK_DOWN))) {
		if (trans.y < 0.005 && trans.y > -0.005) {
			trans.y = 0;
		}
		else {
			trans.y = (abs(trans.y) - speedRate) * (abs(trans.y) / trans.y);  // absolute value of Y * de curent direction of Y (positive or negative)
		}
	}

	//Add speed to vectors and normalize trans
	
	pos += trans.GetNormalized() * speed * time.DeltaTime();

}

void Dude::ClampToScreen()
{
	if (pos.x + width > Graphics::ScreenWidth) {
		pos.x = (Graphics::ScreenWidth) - width;
	}
	else if (pos.x < 0) {
		pos.x = 0;
	}

	if (pos.y + height > Graphics::ScreenHeight) {
		pos.y = (Graphics::ScreenHeight) - height;
	}
	else if (pos.y < 0) {
		pos.y = 0;
	}

}


int Dude::GetWidth() const
{
	return width;
}

int Dude::GetHeight() const
{
	return height;
}

void Dude::Draw(Graphics & gfx) const
{

	const int in_x = int(pos.x);
	const int in_y = int(pos.y);

	gfx.PutPixel(7 + in_x, 0 + in_y, 0, 0, 0);
	gfx.PutPixel(8 + in_x, 0 + in_y, 0, 0, 0);
	gfx.PutPixel(9 + in_x, 0 + in_y, 0, 0, 0);
	gfx.PutPixel(10 + in_x, 0 + in_y, 0, 0, 0);
	gfx.PutPixel(11 + in_x, 0 + in_y, 0, 0, 0);
	gfx.PutPixel(12 + in_x, 0 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 1 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 1 + in_y, 0, 0, 0);
	gfx.PutPixel(7 + in_x, 1 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 1 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 1 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 1 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 1 + in_y, 254, 221, 88);
	gfx.PutPixel(12 + in_x, 1 + in_y, 254, 221, 88);
	gfx.PutPixel(13 + in_x, 1 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 1 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 2 + in_y, 0, 0, 0);
	gfx.PutPixel(4 + in_x, 2 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(6 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(12 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(13 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(14 + in_x, 2 + in_y, 254, 221, 88);
	gfx.PutPixel(15 + in_x, 2 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 2 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 3 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(5 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(6 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(12 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(13 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(14 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(15 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(16 + in_x, 3 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 3 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 4 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(5 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(6 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(12 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(13 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(14 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(15 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(16 + in_x, 4 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 4 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(3 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(4 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(6 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(12 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(13 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(15 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(16 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 5 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 5 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 6 + in_y, 255, 255, 255);
	gfx.PutPixel(4 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 6 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 6 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 6 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 6 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(11 + in_x, 6 + in_y, 255, 255, 255);
	gfx.PutPixel(12 + in_x, 6 + in_y, 255, 255, 255);
	gfx.PutPixel(13 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(15 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 6 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 6 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 6 + in_y, 0, 0, 0);
	gfx.PutPixel(0 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 7 + in_y, 255, 255, 255);
	gfx.PutPixel(3 + in_x, 7 + in_y, 255, 255, 255);
	gfx.PutPixel(4 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 7 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 7 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 7 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 7 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(11 + in_x, 7 + in_y, 255, 255, 255);
	gfx.PutPixel(12 + in_x, 7 + in_y, 255, 255, 255);
	gfx.PutPixel(13 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(15 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 7 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 7 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 7 + in_y, 254, 221, 88);
	gfx.PutPixel(19 + in_x, 7 + in_y, 0, 0, 0);
	gfx.PutPixel(0 + in_x, 8 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 8 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 8 + in_y, 255, 255, 255);
	gfx.PutPixel(3 + in_x, 8 + in_y, 255, 255, 255);
	gfx.PutPixel(4 + in_x, 8 + in_y, 255, 255, 255);
	gfx.PutPixel(5 + in_x, 8 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 8 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 8 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 8 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 8 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 8 + in_y, 0, 0, 0);
	gfx.PutPixel(11 + in_x, 8 + in_y, 255, 255, 255);
	gfx.PutPixel(12 + in_x, 8 + in_y, 255, 255, 255);
	gfx.PutPixel(13 + in_x, 8 + in_y, 255, 255, 255);
	gfx.PutPixel(14 + in_x, 8 + in_y, 255, 255, 255);
	gfx.PutPixel(15 + in_x, 8 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 8 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 8 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 8 + in_y, 254, 221, 88);
	gfx.PutPixel(19 + in_x, 8 + in_y, 0, 0, 0);
	gfx.PutPixel(0 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(2 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(4 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(12 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(13 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(15 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(16 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 9 + in_y, 254, 221, 88);
	gfx.PutPixel(19 + in_x, 9 + in_y, 0, 0, 0);
	gfx.PutPixel(0 + in_x, 10 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(2 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(3 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(5 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(6 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(12 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(13 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(14 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(15 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(16 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 10 + in_y, 254, 221, 88);
	gfx.PutPixel(19 + in_x, 10 + in_y, 0, 0, 0);
	gfx.PutPixel(0 + in_x, 11 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(2 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(3 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(5 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(6 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(7 + in_x, 11 + in_y, 20, 14, 18);
	gfx.PutPixel(8 + in_x, 11 + in_y, 18, 11, 14);
	gfx.PutPixel(9 + in_x, 11 + in_y, 18, 12, 14);
	gfx.PutPixel(10 + in_x, 11 + in_y, 18, 12, 14);
	gfx.PutPixel(11 + in_x, 11 + in_y, 21, 13, 16);
	gfx.PutPixel(12 + in_x, 11 + in_y, 24, 11, 15);
	gfx.PutPixel(13 + in_x, 11 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(15 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(16 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 11 + in_y, 254, 221, 88);
	gfx.PutPixel(19 + in_x, 11 + in_y, 0, 0, 0);
	gfx.PutPixel(0 + in_x, 12 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(2 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(3 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(5 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(6 + in_x, 12 + in_y, 23, 9, 23);
	gfx.PutPixel(7 + in_x, 12 + in_y, 135, 26, 68);
	gfx.PutPixel(8 + in_x, 12 + in_y, 135, 26, 68);
	gfx.PutPixel(9 + in_x, 12 + in_y, 135, 26, 68);
	gfx.PutPixel(10 + in_x, 12 + in_y, 135, 26, 68);
	gfx.PutPixel(11 + in_x, 12 + in_y, 135, 26, 68);
	gfx.PutPixel(12 + in_x, 12 + in_y, 135, 26, 68);
	gfx.PutPixel(13 + in_x, 12 + in_y, 135, 26, 68);
	gfx.PutPixel(14 + in_x, 12 + in_y, 0, 0, 0);
	gfx.PutPixel(15 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(16 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 12 + in_y, 254, 221, 88);
	gfx.PutPixel(19 + in_x, 12 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 13 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 13 + in_y, 254, 221, 88);
	gfx.PutPixel(3 + in_x, 13 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 13 + in_y, 254, 221, 88);
	gfx.PutPixel(5 + in_x, 13 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(7 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(8 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(9 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(10 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(11 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(12 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(13 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(14 + in_x, 13 + in_y, 135, 26, 68);
	gfx.PutPixel(15 + in_x, 13 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 13 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 13 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 13 + in_y, 0, 0, 0);
	gfx.PutPixel(1 + in_x, 14 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 14 + in_y, 254, 221, 88);
	gfx.PutPixel(3 + in_x, 14 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 14 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 14 + in_y, 135, 26, 68);
	gfx.PutPixel(6 + in_x, 14 + in_y, 135, 26, 68);
	gfx.PutPixel(7 + in_x, 14 + in_y, 135, 26, 68);
	gfx.PutPixel(8 + in_x, 14 + in_y, 135, 26, 68);
	gfx.PutPixel(9 + in_x, 14 + in_y, 251, 192, 224);
	gfx.PutPixel(10 + in_x, 14 + in_y, 251, 192, 224);
	gfx.PutPixel(11 + in_x, 14 + in_y, 251, 192, 224);
	gfx.PutPixel(12 + in_x, 14 + in_y, 251, 192, 224);
	gfx.PutPixel(13 + in_x, 14 + in_y, 135, 26, 68);
	gfx.PutPixel(14 + in_x, 14 + in_y, 135, 26, 68);
	gfx.PutPixel(15 + in_x, 14 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 14 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 14 + in_y, 254, 221, 88);
	gfx.PutPixel(18 + in_x, 14 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 15 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 15 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 15 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 15 + in_y, 135, 26, 68);
	gfx.PutPixel(6 + in_x, 15 + in_y, 135, 26, 68);
	gfx.PutPixel(7 + in_x, 15 + in_y, 135, 26, 68);
	gfx.PutPixel(8 + in_x, 15 + in_y, 251, 192, 224);
	gfx.PutPixel(9 + in_x, 15 + in_y, 251, 192, 224);
	gfx.PutPixel(10 + in_x, 15 + in_y, 251, 192, 224);
	gfx.PutPixel(11 + in_x, 15 + in_y, 251, 192, 224);
	gfx.PutPixel(12 + in_x, 15 + in_y, 251, 192, 224);
	gfx.PutPixel(13 + in_x, 15 + in_y, 251, 192, 224);
	gfx.PutPixel(14 + in_x, 15 + in_y, 135, 26, 68);
	gfx.PutPixel(15 + in_x, 15 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 15 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 15 + in_y, 0, 0, 0);
	gfx.PutPixel(2 + in_x, 16 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 16 + in_y, 254, 221, 88);
	gfx.PutPixel(4 + in_x, 16 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 16 + in_y, 135, 26, 68);
	gfx.PutPixel(6 + in_x, 16 + in_y, 135, 26, 68);
	gfx.PutPixel(7 + in_x, 16 + in_y, 135, 26, 68);
	gfx.PutPixel(8 + in_x, 16 + in_y, 251, 192, 224);
	gfx.PutPixel(9 + in_x, 16 + in_y, 251, 192, 224);
	gfx.PutPixel(10 + in_x, 16 + in_y, 251, 192, 224);
	gfx.PutPixel(11 + in_x, 16 + in_y, 251, 192, 224);
	gfx.PutPixel(12 + in_x, 16 + in_y, 251, 192, 224);
	gfx.PutPixel(13 + in_x, 16 + in_y, 251, 192, 224);
	gfx.PutPixel(14 + in_x, 16 + in_y, 135, 26, 68);
	gfx.PutPixel(15 + in_x, 16 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 16 + in_y, 254, 221, 88);
	gfx.PutPixel(17 + in_x, 16 + in_y, 0, 0, 0);
	gfx.PutPixel(3 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(4 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(7 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(8 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(9 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(10 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(11 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(12 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(13 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(15 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(16 + in_x, 17 + in_y, 0, 0, 0);
	gfx.PutPixel(5 + in_x, 18 + in_y, 0, 0, 0);
	gfx.PutPixel(6 + in_x, 18 + in_y, 0, 0, 0);
	gfx.PutPixel(7 + in_x, 18 + in_y, 254, 221, 88);
	gfx.PutPixel(8 + in_x, 18 + in_y, 254, 221, 88);
	gfx.PutPixel(9 + in_x, 18 + in_y, 254, 221, 88);
	gfx.PutPixel(10 + in_x, 18 + in_y, 254, 221, 88);
	gfx.PutPixel(11 + in_x, 18 + in_y, 254, 221, 88);
	gfx.PutPixel(12 + in_x, 18 + in_y, 254, 221, 88);
	gfx.PutPixel(13 + in_x, 18 + in_y, 0, 0, 0);
	gfx.PutPixel(14 + in_x, 18 + in_y, 0, 0, 0);
	gfx.PutPixel(7 + in_x, 19 + in_y, 0, 0, 0);
	gfx.PutPixel(8 + in_x, 19 + in_y, 0, 0, 0);
	gfx.PutPixel(9 + in_x, 19 + in_y, 0, 0, 0);
	gfx.PutPixel(10 + in_x, 19 + in_y, 0, 0, 0);
	gfx.PutPixel(11 + in_x, 19 + in_y, 0, 0, 0);
	gfx.PutPixel(12 + in_x, 19 + in_y, 0, 0, 0);
}

Vec2 Dude::GetPos() const
{
	return pos;
}



