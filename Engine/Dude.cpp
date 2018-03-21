#include "Dude.h"

#include "Graphics.h"

Dude::Dude()
{
}


Dude::~Dude()
{
}

void Dude::clampToScreen()
{
	const int right = x + width;
	if (x < 0) {
		x = 0;
	}
	else if (x + width >= Graphics::ScreenWidth) {
		x = (Graphics::ScreenWidth - 1) - width;
	}

	if (y < 0) {
		y = 0;
	}
	else if (y + height >= Graphics::ScreenHeight) {
		y = (Graphics::ScreenHeight - 1) - height;
	}

}
