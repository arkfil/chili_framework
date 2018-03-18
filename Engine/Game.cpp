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
	shapeIsChanged = false;
	vx = 0;
	vy = 0;
	inhibitUp = false;
	inhibitDown = false;
	inhibitLeft = false;
	inhibitRight = false;


	x2 = 155;
	y2 = 450;
	r2 = 255;
	g2 = 255;
	b2 = 255;


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


	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitUp) {}
		else{
			--vy;
			inhibitUp = true;
		}
	}
	else {
		inhibitUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (inhibitDown) {}
		else {
			++vy;
			inhibitDown = true;
		}
	}
	else {
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (inhibitLeft) {}
		else {
			--vx;
			inhibitLeft = true;
		}
	}
	else {
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (inhibitRight) {}
		else {
			++vx;
			inhibitRight = true;
		}
	}
	else {
		inhibitRight = false;
	}
	
	g = wnd.kbd.KeyIsPressed(VK_CONTROL) ? 0 : 255;


	//shapeIsChanged = ;
	shapeIsChanged = (x >= 200 && x <= 350) || wnd.kbd.KeyIsPressed(VK_SHIFT);


	x += vx;
	y += vy;


	if (x + 6 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 7;
		vx = 0;
		vy = 0;
	}
	if (x - 6 <= 1){
		x = 7;
		vx = 0;
		vy = 0;
	}
	if (y + 6 >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 7;
		vx = 0;
		vy = 0;
	}
	if (y - 6 <= 1) {
		y = 7;
		vx = 0;
		vy = 0;
	}


	//Ovelaping
	if ((x + 6 >= x2 - 6) && (x - 6 <= x2 + 6) && (y+6) >= (y2-6)&&(y-6)<=(y2+6)) {
		r = 255;
		g = 0;
		b = 0;
	}
	else {
		r = 255; g = 255; b = 255;
	}


	
	

}


void Game::ComposeFrame()
{
  

		if ( shapeIsChanged ) {

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

///////////////////////////////////////////////////////////////////////////

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



		// SECOD SQUARE
		{
			// Horizontal top-left
			gfx.PutPixel(x2 - 5, y2 - 5, r2, g2, b2);
			gfx.PutPixel(x2 - 5, y2 - 4, r2, g2, b2);
			gfx.PutPixel(x2 - 5, y2 - 3, r2, g2, b2);

			// Horizontal bottom-left
			gfx.PutPixel(x2 - 5, y2 + 3, r2, g2, b2);
			gfx.PutPixel(x2 - 5, y2 + 4, r2, g2, b2);
			gfx.PutPixel(x2 - 5, y2 + 5, r2, g2, b2);

			// Horizontal top-right
			gfx.PutPixel(x2 + 5, y2 - 5, r2, g2, b2);
			gfx.PutPixel(x2 + 5, y2 - 4, r2, g2, b2);
			gfx.PutPixel(x2 + 5, y2 - 3, r2, g2, b2);

			// Horizontal bottom-right
			gfx.PutPixel(x2 + 5, y2 + 3, r2, g2, b2);
			gfx.PutPixel(x2 + 5, y2 + 4, r2, g2, b2);
			gfx.PutPixel(x2 + 5, y2 + 5, r2, g2, b2);

			/////////////////////////////////////////////

			// Vertical top-left
			gfx.PutPixel(x2 - 4, y2 - 5, r2, g2, b2);
			gfx.PutPixel(x2 - 3, y2 - 5, r2, g2, b2);
			gfx.PutPixel(x2 - 2, y2 - 5, r2, g2, b2);

			// Vertical bottom-left
			gfx.PutPixel(x2 - 4, y2 + 5, r2, g2, b2);
			gfx.PutPixel(x2 - 3, y2 + 5, r2, g2, b2);
			gfx.PutPixel(x2 - 2, y2 + 5, r2, g2, b2);

			// Vertical top-right
			gfx.PutPixel(x2 + 4, y2 - 5, r2, g2, b2);
			gfx.PutPixel(x2 + 3, y2 - 5, r2, g2, b2);
			gfx.PutPixel(x2 + 2, y2 - 5, r2, g2, b2);

			// Vertical bottom-right
			gfx.PutPixel(x2 + 4, y2 + 5, r2, g2, b2);
			gfx.PutPixel(x2 + 3, y2 + 5, r2, g2, b2);
			gfx.PutPixel(x2 + 2, y2 + 4, r2, g2, b2);

		}
		






}
