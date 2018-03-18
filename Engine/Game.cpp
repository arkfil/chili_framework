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
}

int x = 200;
int y = 400;
int r = 255, g = 255, b = 255;
void Game::ComposeFrame()
{
   //800x600

	y = wnd.kbd.KeyIsPressed(VK_UP) ? ----y : y;
	y = wnd.kbd.KeyIsPressed(VK_DOWN) ? ++++y : y;
	x = wnd.kbd.KeyIsPressed(VK_RIGHT) ? ++++x : x;
	x = wnd.kbd.KeyIsPressed(VK_LEFT) ? ----x : x;


	g = wnd.kbd.KeyIsPressed(VK_CONTROL) ? 0 : 255;






	if (x>=7 && y>=7 && x<=793 && y<=593) {
		if (wnd.kbd.KeyIsPressed(VK_SHIFT)) {

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
			gfx.PutPixel(x + 2, y + 5, r, g, b);


		}
		else {
			// Vertical top
			gfx.PutPixel(x, y - 6, r, g, b);
			gfx.PutPixel(x, y - 5, r, g, b);
			gfx.PutPixel(x, y - 4, r, g, b);
			gfx.PutPixel(x, y - 3, r, g, b);
			gfx.PutPixel(x, y - 2, r, g, b);

			// Vertical bottom
			gfx.PutPixel(x, y + 2, r, g, b);
			gfx.PutPixel(x, y + 3, r, g, b);
			gfx.PutPixel(x, y + 4, r, g, b);
			gfx.PutPixel(x, y + 5, r, g, b);
			gfx.PutPixel(x, y + 6, r, g, b);

			// Horizontal left
			gfx.PutPixel(x - 2, y, r, g, b);
			gfx.PutPixel(x - 3, y, r, g, b);
			gfx.PutPixel(x - 4, y, r, g, b);
			gfx.PutPixel(x - 5, y, r, g, b);
			gfx.PutPixel(x - 6, y, r, g, b);

			// Horizontal right
			gfx.PutPixel(x + 2, y, r, g, b);
			gfx.PutPixel(x + 3, y, r, g, b);
			gfx.PutPixel(x + 4, y, r, g, b);
			gfx.PutPixel(x + 5, y, r, g, b);
			gfx.PutPixel(x + 6, y, r, g, b);
		}
		
	}
	else if (y >= 593) y = 7;
	else if (y <= 7 ) y = 593;
	else if (x <= 7) x = 793;
	else if (x >= 793) x = 7;
	
}
