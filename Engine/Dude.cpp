#include "Dude.h"
#include <math.h>
#include "Graphics.h"
#include "Keyboard.h"


void Dude::MoveDude(const Keyboard& kbd, class Timer time) {

	//Move dude
	

	if (kbd.KeyIsPressed(VK_LEFT)) {

		x_trans -= speedRate;

	}
	if (kbd.KeyIsPressed(VK_RIGHT)) {

		x_trans += speedRate;
	}

	if (kbd.KeyIsPressed(VK_UP)) {

		y_trans -= speedRate;

	}
	if (kbd.KeyIsPressed(VK_DOWN)) {

		y_trans += speedRate;

	}

	// Set max X and Y values

	if (x_trans >= 1) {
		x_trans = 1;
	}
	else if (x_trans <= -1) {
		x_trans = -1;
	}
	if (y_trans >= 1) {
		y_trans = 1;
	}
	else if (y_trans <= -1) {
		y_trans = -1;
	}


	// Decelerate when key is not pressed

	if (!(kbd.KeyIsPressed(VK_LEFT)) && !(kbd.KeyIsPressed(VK_RIGHT))) {
		if (x_trans < 0.005 && x_trans > -0.005) {
			x_trans = 0;
		}
		else {
			x_trans = (abs(x_trans) - speedRate) * (abs(x_trans) / x_trans); // absolute value of X * de curent direction of X (positive or negative)
		}
	}

	if (!(kbd.KeyIsPressed(VK_UP)) && !(kbd.KeyIsPressed(VK_DOWN))) {
		if (y_trans < 0.005 && y_trans > -0.005) {
			y_trans = 0;
		}
		else {
			y_trans = (abs(y_trans) - speedRate) * (abs(y_trans) / y_trans);  // absolute value of Y * de curent direction of Y (positive or negative)
		}
	}

	//Equalize hipotenuse vector 

	float x_temp;
	float y_temp;

	if (y_trans == 0) {
		x_temp = x_trans;
	}
	else {
		x_temp = x_trans / sqrt(((abs(y_trans*y_trans)) + 1));
	}


	if (x_trans == 0) {
		y_temp = y_trans;
	}
	else {
		y_temp = y_trans / sqrt(((abs(x_trans*x_trans)) + 1));

	}
	//Add speed to vectors and map values to x and y

	x += x_temp * speed * time.DeltaTime();
	y += y_temp * speed * time.DeltaTime();

}

void Dude::ClampToScreen()
{
	if (x + width > Graphics::ScreenWidth) {
		x = (Graphics::ScreenWidth) - width;
	}
	else if (x < 0) {
		x = 0;
	}

	if (y + height > Graphics::ScreenHeight) {
		y = (Graphics::ScreenHeight) - height;
	}
	else if (y < 0) {
		y = 0;
	}

}

void Dude::Draw(Graphics & gfx) const
{

	const int in_x = int(x);
	const int in_y = int(y);

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

float Dude::GetX() const
{
	return x;
}

float Dude::GetY() const
{
	return y;
}

int Dude::GetWidth() const
{
	return width;
}

int Dude::GetHeight() const
{
	return height;
}
