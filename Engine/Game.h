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
	void DrawFace(int x, int y );
	void DrawPoo(int x, int y);

	void DrawTitleScreen(int x, int y);
	void DrawGameOver(int x, int y);

	int ClampScreenX(int x, int width);
	int ClampScreenY(int y, int height);

	int DriftAroundX(bool &direcX, int x, int width);
	int DriftAroundY( bool &direcY, int y, int height);

	
	bool isColliding(int x0, int y0, int width0, int height0,
		int x1, int y1, int width1, int height1);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

	int dudeX = 200;
	int dudeY = 200;

	int dudeWidth = 20;
	int dudeHeight = 20;

	bool isStarted = false;

	int poo0X = 120;
	int poo0Y = 90;

	int poo1X = 500;
	int poo1Y = 400;

	int poo2X = 300;
	int poo2Y = 80;

	bool poo0MoveY = true;
	bool poo0MoveX = false;
	bool poo1MoveY = true;
	bool poo1MoveX = false;
	bool poo2MoveY = true;
	bool poo2MoveX = false;

	int pooWidth = 24;
	int pooHeight = 24;

	int poo0IsEaten = false;
	int poo1IsEaten = false;
	int poo2IsEaten = false;

	/********************************/
};