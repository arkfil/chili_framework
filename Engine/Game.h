/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawBoard(int x, int y, int r, int g, int b);
	void KeepBoxInBouderies(int &y);
	void BoxMovementSupport( int &y, int down, int up);
	void ShowBall( int x, int y, int radius, int r, int g, int b );

	void MoveBall(int &x, int &y, int mod_x, int mod_y);
	void KeepBallInBouderies(int &ball_x, int &ball_y, int &mod_x, int &mod_y);

	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

	int board1_baseX;
	int board1_baseY;
	int board1_r, board1_g, board1_b;

	int board2_baseX;
	int board2_baseY;
	int board2_r, board2_g, board2_b;

	int ball_x;
	int ball_y;
	int ball_r, ball_g, ball_b;

	int mod_x, mod_y;


	/********************************/
};