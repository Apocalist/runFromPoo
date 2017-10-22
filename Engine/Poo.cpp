#include "Poo.h"
#include "Graphics.h"
#include <random>
#include "Dude.h"


void Poo::Update(Timer& time) {

	//x += x_dir * time.DeltaTime();
	//y += y_dir * time.DeltaTime();
	pos += dir * time.DeltaTime();

	// Bounce off the screen limits

	const int w = Graphics::ScreenWidth - int(width) - 1;
	const int h = Graphics::ScreenHeight - int(height) - 1;

	if ( pos.x <= 0 ||pos.x >= w) {
		dir.x *= -1;
	}
	if (pos.y <= 0 || pos.y >= h) {
		dir.y *= -1;
	}

	//****
}

void Poo::RandPos( float( in_x), float(in_y), float in_x_dir, float in_y_dir,Timer& time)
{
	
	pos.x = in_x;
	pos.y = in_y;


	dir.x = in_x_dir;
	dir.y = in_y_dir;


}

void Poo::isColliding(const Dude& dude)
{
	if (
		pos.x + width >= dude.GetPos().x &&
		pos.x <= dude.GetPos().x + dude.GetWidth() &&
		pos.y + height >= dude.GetPos().y &&
		pos.y <= dude.GetPos().y + dude.GetHeight()
		) 
		{
		isEaten = true;
		}

}

bool Poo::IsEaten() const
{
	return isEaten;
}

float Poo::GetWidth() const
{
	return width;
}

float Poo::GetHeight() const
{
	return height;
}

void Poo::Reset()
{
	isEaten = false;
}

void Poo::Draw(Graphics& gfx)
{
	const int in_x = int(pos.x);
	const int in_y = int(pos.y);
		
	gfx.PutPixel(14 + in_x, 0 + in_y, 138, 77, 0);
	gfx.PutPixel(7 + in_x, 1 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 1 + in_y, 138, 77, 0);
	gfx.PutPixel(20 + in_x, 1 + in_y, 138, 77, 0);
	gfx.PutPixel(6 + in_x, 2 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 2 + in_y, 138, 77, 0);
	gfx.PutPixel(20 + in_x, 2 + in_y, 138, 77, 0);
	gfx.PutPixel(6 + in_x, 3 + in_y, 138, 77, 0);
	gfx.PutPixel(6 + in_x, 4 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 4 + in_y, 138, 77, 0);
	gfx.PutPixel(21 + in_x, 4 + in_y, 138, 77, 0);
	gfx.PutPixel(7 + in_x, 5 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 5 + in_y, 138, 77, 0);
	gfx.PutPixel(21 + in_x, 5 + in_y, 138, 77, 0);
	gfx.PutPixel(7 + in_x, 6 + in_y, 138, 77, 0);
	gfx.PutPixel(20 + in_x, 6 + in_y, 138, 77, 0);
	gfx.PutPixel(6 + in_x, 7 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 7 + in_y, 51, 28, 0);
	gfx.PutPixel(15 + in_x, 7 + in_y, 51, 28, 0);
	gfx.PutPixel(20 + in_x, 7 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 8 + in_y, 51, 28, 0);
	gfx.PutPixel(13 + in_x, 8 + in_y, 51, 28, 0);
	gfx.PutPixel(14 + in_x, 8 + in_y, 51, 28, 0);
	gfx.PutPixel(7 + in_x, 9 + in_y, 138, 77, 0);
	gfx.PutPixel(11 + in_x, 9 + in_y, 51, 28, 0);
	gfx.PutPixel(12 + in_x, 9 + in_y, 102, 57, 0);
	gfx.PutPixel(13 + in_x, 9 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 9 + in_y, 138, 77, 0);
	gfx.PutPixel(15 + in_x, 9 + in_y, 51, 28, 0);
	gfx.PutPixel(21 + in_x, 9 + in_y, 138, 77, 0);
	gfx.PutPixel(10 + in_x, 10 + in_y, 51, 28, 0);
	gfx.PutPixel(11 + in_x, 10 + in_y, 51, 28, 0);
	gfx.PutPixel(12 + in_x, 10 + in_y, 102, 57, 0);
	gfx.PutPixel(13 + in_x, 10 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 10 + in_y, 138, 77, 0);
	gfx.PutPixel(15 + in_x, 10 + in_y, 51, 28, 0);
	gfx.PutPixel(20 + in_x, 10 + in_y, 138, 77, 0);
	gfx.PutPixel(9 + in_x, 11 + in_y, 51, 28, 0);
	gfx.PutPixel(10 + in_x, 11 + in_y, 138, 77, 0);
	gfx.PutPixel(11 + in_x, 11 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 11 + in_y, 51, 28, 0);
	gfx.PutPixel(13 + in_x, 11 + in_y, 51, 28, 0);
	gfx.PutPixel(14 + in_x, 11 + in_y, 51, 28, 0);
	gfx.PutPixel(15 + in_x, 11 + in_y, 51, 28, 0);
	gfx.PutPixel(16 + in_x, 11 + in_y, 51, 28, 0);
	gfx.PutPixel(9 + in_x, 12 + in_y, 51, 28, 0);
	gfx.PutPixel(10 + in_x, 12 + in_y, 138, 77, 0);
	gfx.PutPixel(11 + in_x, 12 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 12 + in_y, 111, 62, 0);
	gfx.PutPixel(13 + in_x, 12 + in_y, 102, 57, 0);
	gfx.PutPixel(14 + in_x, 12 + in_y, 102, 57, 0);
	gfx.PutPixel(15 + in_x, 12 + in_y, 102, 57, 0);
	gfx.PutPixel(16 + in_x, 12 + in_y, 51, 28, 0);
	gfx.PutPixel(9 + in_x, 13 + in_y, 51, 28, 0);
	gfx.PutPixel(10 + in_x, 13 + in_y, 109, 61, 0);
	gfx.PutPixel(11 + in_x, 13 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 13 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 13 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 13 + in_y, 138, 77, 0);
	gfx.PutPixel(15 + in_x, 13 + in_y, 138, 77, 0);
	gfx.PutPixel(16 + in_x, 13 + in_y, 51, 28, 0);
	gfx.PutPixel(5 + in_x, 14 + in_y, 51, 28, 0);
	gfx.PutPixel(7 + in_x, 14 + in_y, 51, 28, 0);
	gfx.PutPixel(8 + in_x, 14 + in_y, 51, 28, 0);
	gfx.PutPixel(9 + in_x, 14 + in_y, 51, 28, 0);
	gfx.PutPixel(10 + in_x, 14 + in_y, 51, 28, 0);
	gfx.PutPixel(11 + in_x, 14 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 14 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 14 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 14 + in_y, 138, 77, 0);
	gfx.PutPixel(15 + in_x, 14 + in_y, 138, 77, 0);
	gfx.PutPixel(16 + in_x, 14 + in_y, 51, 28, 0);
	gfx.PutPixel(4 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(5 + in_x, 15 + in_y, 138, 77, 0);
	gfx.PutPixel(6 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(7 + in_x, 15 + in_y, 116, 65, 0);
	gfx.PutPixel(8 + in_x, 15 + in_y, 138, 77, 0);
	gfx.PutPixel(9 + in_x, 15 + in_y, 138, 77, 0);
	gfx.PutPixel(10 + in_x, 15 + in_y, 138, 77, 0);
	gfx.PutPixel(11 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(12 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(13 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(14 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(15 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(16 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(17 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(18 + in_x, 15 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 16 + in_y, 51, 28, 0);
	gfx.PutPixel(2 + in_x, 16 + in_y, 51, 28, 0);
	gfx.PutPixel(3 + in_x, 16 + in_y, 51, 28, 0);
	gfx.PutPixel(4 + in_x, 16 + in_y, 51, 28, 0);
	gfx.PutPixel(5 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(6 + in_x, 16 + in_y, 51, 28, 0);
	gfx.PutPixel(7 + in_x, 16 + in_y, 116, 65, 0);
	gfx.PutPixel(8 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(9 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(10 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(11 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 16 + in_y, 109, 61, 0);
	gfx.PutPixel(14 + in_x, 16 + in_y, 51, 28, 0);
	gfx.PutPixel(15 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(16 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(17 + in_x, 16 + in_y, 138, 77, 0);
	gfx.PutPixel(18 + in_x, 16 + in_y, 123, 69, 0);
	gfx.PutPixel(19 + in_x, 16 + in_y, 51, 28, 0);
	gfx.PutPixel(0 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 17 + in_y, 87, 49, 0);
	gfx.PutPixel(2 + in_x, 17 + in_y, 87, 49, 0);
	gfx.PutPixel(3 + in_x, 17 + in_y, 87, 49, 0);
	gfx.PutPixel(4 + in_x, 17 + in_y, 87, 49, 0);
	gfx.PutPixel(5 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(6 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(7 + in_x, 17 + in_y, 43, 24, 0);
	gfx.PutPixel(8 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(9 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(10 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(11 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(12 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(13 + in_x, 17 + in_y, 40, 22, 0);
	gfx.PutPixel(14 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(15 + in_x, 17 + in_y, 138, 77, 0);
	gfx.PutPixel(16 + in_x, 17 + in_y, 138, 77, 0);
	gfx.PutPixel(17 + in_x, 17 + in_y, 138, 77, 0);
	gfx.PutPixel(18 + in_x, 17 + in_y, 123, 69, 0);
	gfx.PutPixel(19 + in_x, 17 + in_y, 51, 28, 0);
	gfx.PutPixel(0 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 18 + in_y, 138, 77, 0);
	gfx.PutPixel(2 + in_x, 18 + in_y, 138, 77, 0);
	gfx.PutPixel(3 + in_x, 18 + in_y, 138, 77, 0);
	gfx.PutPixel(4 + in_x, 18 + in_y, 138, 77, 0);
	gfx.PutPixel(5 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(6 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(7 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(8 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(9 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(10 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(11 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(12 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(13 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(14 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(15 + in_x, 18 + in_y, 138, 77, 0);
	gfx.PutPixel(16 + in_x, 18 + in_y, 138, 77, 0);
	gfx.PutPixel(17 + in_x, 18 + in_y, 138, 77, 0);
	gfx.PutPixel(18 + in_x, 18 + in_y, 123, 69, 0);
	gfx.PutPixel(19 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(20 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(21 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(22 + in_x, 18 + in_y, 51, 28, 0);
	gfx.PutPixel(0 + in_x, 19 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(2 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(3 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(4 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(5 + in_x, 19 + in_y, 51, 28, 0);
	gfx.PutPixel(6 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(7 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(8 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(9 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(10 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(11 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(15 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(16 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(17 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(18 + in_x, 19 + in_y, 123, 69, 0);
	gfx.PutPixel(19 + in_x, 19 + in_y, 51, 28, 0);
	gfx.PutPixel(20 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(21 + in_x, 19 + in_y, 138, 77, 0);
	gfx.PutPixel(22 + in_x, 19 + in_y, 65, 36, 0);
	gfx.PutPixel(23 + in_x, 19 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 20 + in_y, 51, 28, 0);
	gfx.PutPixel(2 + in_x, 20 + in_y, 51, 28, 0);
	gfx.PutPixel(3 + in_x, 20 + in_y, 51, 28, 0);
	gfx.PutPixel(4 + in_x, 20 + in_y, 51, 28, 0);
	gfx.PutPixel(5 + in_x, 20 + in_y, 51, 28, 0);
	gfx.PutPixel(6 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(7 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(8 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(9 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(10 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(11 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(12 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(13 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(14 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(15 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(16 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(17 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(18 + in_x, 20 + in_y, 123, 69, 0);
	gfx.PutPixel(19 + in_x, 20 + in_y, 51, 28, 0);
	gfx.PutPixel(20 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(21 + in_x, 20 + in_y, 138, 77, 0);
	gfx.PutPixel(22 + in_x, 20 + in_y, 65, 36, 0);
	gfx.PutPixel(23 + in_x, 20 + in_y, 51, 28, 0);
	gfx.PutPixel(0 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 21 + in_y, 138, 77, 0);
	gfx.PutPixel(2 + in_x, 21 + in_y, 138, 77, 0);
	gfx.PutPixel(3 + in_x, 21 + in_y, 138, 77, 0);
	gfx.PutPixel(4 + in_x, 21 + in_y, 138, 77, 0);
	gfx.PutPixel(5 + in_x, 21 + in_y, 138, 77, 0);
	gfx.PutPixel(6 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(7 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(8 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(9 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(10 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(11 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(12 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(13 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(14 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(15 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(16 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(17 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(18 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(20 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(21 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(22 + in_x, 21 + in_y, 51, 28, 0);
	gfx.PutPixel(0 + in_x, 22 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 22 + in_y, 65, 36, 0);
	gfx.PutPixel(2 + in_x, 22 + in_y, 65, 36, 0);
	gfx.PutPixel(3 + in_x, 22 + in_y, 65, 36, 0);
	gfx.PutPixel(4 + in_x, 22 + in_y, 65, 36, 0);
	gfx.PutPixel(5 + in_x, 22 + in_y, 65, 36, 0);
	gfx.PutPixel(6 + in_x, 22 + in_y, 51, 28, 0);
	gfx.PutPixel(1 + in_x, 23 + in_y, 51, 28, 0);
	gfx.PutPixel(2 + in_x, 23 + in_y, 51, 28, 0);
	gfx.PutPixel(3 + in_x, 23 + in_y, 51, 28, 0);
	gfx.PutPixel(4 + in_x, 23 + in_y, 51, 28, 0);
	gfx.PutPixel(5 + in_x, 23 + in_y, 51, 28, 0);
	gfx.PutPixel(6 + in_x, 23 + in_y, 51, 28, 0);

}


