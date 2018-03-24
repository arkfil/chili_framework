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
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (y + height <= Graphics::ScreenHeight - 1) {
			++y;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (y>1) {
			--y;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (x + width <= Graphics::ScreenWidth - 1) {
			++x;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (x > 1) {
			--x;
		}
	}
////////////////////////////////////////////////
	if (wnd.kbd.KeyIsPressed('S')) {
		if(y+height + 1<= Graphics::ScreenHeight)
			++height;
	}
	if (wnd.kbd.KeyIsPressed('W')) {
		--height;
	}
	if (wnd.kbd.KeyIsPressed('D')) {
		if (x + width + 1 <= Graphics::ScreenWidth)
			++width;
	}
	if (wnd.kbd.KeyIsPressed('A')) {
		--width;
	}

}


void Game::ComposeFrame()
{

	for (int i = x; i <= x+width-1; ++i) {
		for (int j = y; j <= y+ height-1; ++j) {
			gfx.PutPixel(i,j,255,255,255);
		}
	}
}
