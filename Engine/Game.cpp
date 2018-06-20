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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	paddle1({ 20,20 }, 'W', 'S'),
	paddle2({ Graphics::ScreenWidth - 20 - paddle2.GetWidth(), 20 },
		VK_UP, VK_DOWN),
	ball({ (Graphics::ScreenWidth - ball.size) / 2,
		(Graphics::ScreenHeight - ball.size) / 2 })
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
	if (paddle1.IsColliding(ball) || paddle2.IsColliding(ball))
		BALL_SPEED_X *= -1;
	if (ball.GetY() + BALL_SPEED_Y < 0)
		BALL_SPEED_Y *= -1;

	ball.Move(delta_loc);
	paddle1.Move(wnd.kbd);
	paddle2.Move(wnd.kbd);

}

void Game::ComposeFrame()
{
	paddle1.Draw(gfx);
	paddle2.Draw(gfx);
	ball.Draw(gfx);
}
