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
	gfx( wnd ),
	mainSong(L"actionnd.wav")
{
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist(0.0f, 790.0f);
	std::uniform_real_distribution<float> yDist(0.0f, 590.0f);
	for (int i = 0; i < nStars; i++)
	{
		star[i].Spawn(xDist(rng), yDist(rng), 3.0f);
	}
	for (int i = 0; i < nBigStars; i++)
	{
		starB[i].Spawn(xDist(rng), yDist(rng), 6.0f);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}
/*
I want to keep UpdateModel nice and neat. 
Anything that has to do with the ship should be part of ship.Update
*/
void Game::UpdateModel()
{
	const float dt = ft.Mark();

	

	if (gameIsStarted)
	{
		titleSong.StopAll();
		ship.Update(wnd, dt);
		UpdateStars(dt);
		mineM.Update(ship, dt, shieldM);
		eBoostM.Update(ship, dt);
		shieldM.Update(ship, dt, shieldon, shieldoff);
	}
	else
	{
		if (!songIsPlayed)
		{
			titleSong.Play();
			songIsPlayed = true;
		}
		
		PlayerInput();
	}
	
}

void Game::UpdateStars(float dt)
{
	for (int i = 0; i < nStars; i++)
	{
		star[i].Update(dt);
	}

	for (int i = 0; i < nBigStars; i++)
	{
		starB[i].Update(dt * 1.2f);
	}
}

void Game::DrawStars()
{
	for (int i = 0; i < nStars; i++)
	{
		star[i].Draw(gfx);
	}
	for (int i = 0; i < nBigStars; i++)
	{
		starB[i].DrawBig(gfx);
	}
}

void Game::PlayerInput()
{
	if (!gameIsStarted)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gameIsStarted = true;
			mainSong.Play(1.0F, 0.5F);
		}
	}
}

// same thing as in updatemodel goes for composeframe
void Game::ComposeFrame()
{
	if (!gameIsStarted)
	{
		title.Draw(gfx);
	}
	else
	{
		DrawStars();
		shieldM.Draw(gfx);
		ship.Draw(gfx);
		mineM.Draw(gfx, ship);
		eBoostM.Draw(gfx, ship);

		//gfx.DrawLasewr( 200, 100, 50, 200, Colors::Green );
	}
}
