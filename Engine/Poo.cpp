#include "Poo.h"

#include "Graphics.h"


Poo::Poo()
{
}


Poo::~Poo()
{
}

void Poo::Update() {
	x += vx;
	y += vy;

	if (x <= 2 || x >= Graphics::ScreenWidth - 2 - width) {
		vx *= -1;
	}
	if (y <= 2 || y >= Graphics::ScreenHeight - 2 - height) {
		vy *= -1;
	}

}

void Poo::ProcessConsumption(int dudeX, int dudeY, int dudeWidth, int dudeHeight)
{
	const int right0 = dudeX + dudeWidth;
	const int bottom0 = dudeY + dudeHeight;

	const int right1 = x + width;
	const int bottom1 = y + height;


	if (right0 >= x
		&& dudeX <= right1
		&& bottom0 >= y
		&& dudeY <= bottom1) 
	{
		isEaten = true;
	}

}
