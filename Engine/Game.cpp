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

	board1_baseX = 2;
	board1_baseY = 250;
	board1_r = 255, board1_g = 255, board1_b = 255;

	board2_baseX = gfx.ScreenWidth - 12;
	board2_baseY = 250;
	board2_r = 255, board2_g = 255, board2_b = 255;


	ball_x=400;
	ball_y = 300;
	ball_r = 255;
	ball_g = 0;
	ball_b = 0;



	mod_x = 1;
	mod_y = 1;

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
	BoxMovementSupport(board2_baseY, VK_DOWN, VK_UP);

	KeepBoxInBouderies(board2_baseY);
	
	BoxMovementSupport(board1_baseY, 0x53, 0x57);
	
	KeepBoxInBouderies(board1_baseY);


	MoveBall(ball_x, ball_y, mod_x, mod_y);
	


}







void Game::ComposeFrame()
{
	DrawBoard(board1_baseX, board1_baseY, board1_r, board1_g, board1_b);  
	DrawBoard(board2_baseX, board2_baseY, board2_r, board2_g, board2_b);



	ShowBall( ball_x, ball_y, 15, ball_r, ball_g, ball_b );
	MoveBall(ball_x, ball_y, mod_x, mod_y);
	KeepBallInBouderies(ball_x, ball_y, mod_x, mod_y);
}






void Game::DrawBoard(int x,int y, int r, int g, int b) 
{
	for (int i = 1; i <= 100;++i) {
		for (int j = 1; j <= 8; ++j) {
			gfx.PutPixel(x + j, y + i, r, g, b);
		}

	}
	
}

void Game::KeepBoxInBouderies(int & y)
{
	if (y <= 2)
		y = 3;

	if (y >= gfx.ScreenHeight - 102)
		y = gfx.ScreenHeight - 103;
}

void Game::BoxMovementSupport(int & y, int down, int up)
{
	y = wnd.kbd.KeyIsPressed(down) ? y + 4: y;
	y = wnd.kbd.KeyIsPressed(up) ? y - 4 : y;

	
}

void Game::ShowBall(int x, int y, int radius, int r, int g, int b)
{
	int tmp = 0;
	//x = 200;
	//y = 200;


	for (int i = x; i <= x + radius; ++i) {
		for (int j = y; j <= y + radius; ++j) {
			if (sqrt((x - i)*(x - i) + (y - j) * (y - j)) < radius)  {
				gfx.PutPixel(i,j, r, g, b);
			}
		}
	}

	for (int i = x - radius; i <= x; ++i) {
		for (int j = y - radius; j <= y ; ++j) {
			if (sqrt((x - i)*(x - i) + (y - j) * (y - j)) < radius) {
				gfx.PutPixel(i, j, r, g, b);
			}
		}
	}

	for (int i = x + radius; i >= x; --i) {
		for (int j = y- radius; j <= y; ++j) {
			if (sqrt((x - i)*(x - i) + (y - j) * (y - j)) < radius) {
				gfx.PutPixel(i, j, r, g, b);
			}
		}
	}

	for (int i = x - radius; i <= x; ++i) {
		for (int j = y + radius; j >= y; --j) {
			if (sqrt((x - i)*(x - i) + (y - j) * (y - j)) < radius) {
				gfx.PutPixel(i, j, r, g, b);
			}
		}
	}

	




}

void Game::MoveBall(int &x, int &y, int mod_x, int mod_y)
{
	x += mod_x;
	y += mod_y;
}

void Game::KeepBallInBouderies(int & ball_x, int & ball_y, int & mod_x, int & mod_y)
{
	if (ball_x + 16 >= gfx.ScreenWidth) {
		ball_x = gfx.ScreenWidth - 17;
		mod_x *= -1;
	}
	if (ball_x - 16 <= 1) {
		ball_x = 17;
		mod_x *= -1;
	}
	if (ball_y + 16 >= gfx.ScreenHeight) {
		ball_y = gfx.ScreenHeight - 17;
		mod_y *= -1;
	}
	if (ball_y - 16 <= 1) {
		ball_y = 17;
		mod_y *= -1;
	}

	if (ball_x < 1)
		++ball_x;
	if (ball_x > 1)
		--ball_x;
	if (ball_y < 1)
		++ball_y;
	if (ball_y > 1)
		--ball_y;

}

