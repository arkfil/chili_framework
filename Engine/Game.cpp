/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	x = 400;
	y = 300;
	r = 255;
	g = 255;
	b = 255;



	x2 = 155;
	y2 = 450;
	r2 = 255;
	g2 = 255;
	b2 = 255;
	colliding = false;

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//800x600

	if (wnd.kbd.KeyIsPressed(VK_UP)) { y -= 3; }
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) { y += 3; }
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) { x -= 3; }
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) { x += 3; }

	KeepBoxInBouderies(x, y);

	//Ovelaping
	colliding = areBoxesColliding(x, y, x2, y2);	
}




void Game::ComposeFrame()
{
  

		DrawBox(x, y, r, g, b);

		// SECOD SQUARE
		DrawBox(x2,y2,r2,g2,b2);



		if (colliding) {
			r = 0;
			g = 255;
			b = 20;
		}
		else {
			r = 255; g = 255; b = 255;
		}
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	// Horizontal top-left
	gfx.PutPixel(x - 5, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 4, r, g, b);
	gfx.PutPixel(x - 5, y - 3, r, g, b);

	// Horizontal bottom-left
	gfx.PutPixel(x - 5, y + 3, r, g, b);
	gfx.PutPixel(x - 5, y + 4, r, g, b);
	gfx.PutPixel(x - 5, y + 5, r, g, b);

	// Horizontal top-right
	gfx.PutPixel(x + 5, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 4, r, g, b);
	gfx.PutPixel(x + 5, y - 3, r, g, b);

	// Horizontal bottom-right
	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);

	/////////////////////////////////////////////

	// Vertical top-left
	gfx.PutPixel(x - 4, y - 5, r, g, b);
	gfx.PutPixel(x - 3, y - 5, r, g, b);
	gfx.PutPixel(x - 2, y - 5, r, g, b);

	// Vertical bottom-left
	gfx.PutPixel(x - 4, y + 5, r, g, b);
	gfx.PutPixel(x - 3, y + 5, r, g, b);
	gfx.PutPixel(x - 2, y + 5, r, g, b);

	// Vertical top-right
	gfx.PutPixel(x + 4, y - 5, r, g, b);
	gfx.PutPixel(x + 3, y - 5, r, g, b);
	gfx.PutPixel(x + 2, y - 5, r, g, b);

	// Vertical bottom-right
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);

}

bool Game::areBoxesColliding(int x_box1, int y_box1, int x_box2, int y_box2)
{
	return ((x_box1 + 6 >= x_box2 - 6) && (x_box1 - 6 <= x_box2 + 6) && (y_box1 + 6) >= (y_box2 - 6) && (y_box1 - 6) <= (y_box2 + 6));
}

void Game::KeepBoxInBouderies(int &x, int &y)
{
	if (x + 6 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 7;
	}
	if (x - 6 <= 1) {
		x = 7;
	}
	if (y + 6 >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 7;
	}
	if (y - 6 <= 1) {
		y = 7;
	}
}
