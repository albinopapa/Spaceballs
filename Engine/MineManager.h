#pragma once

#include "Mine.h"
#include <random>


class MineManager
{
public:
	MineManager();
	void Update(Ship& ship, float dt);
	void Draw(Graphics & gfx, Ship& ship);
	void CheckCollision( class BulletManager &Bullets, Ship& _Ship );

private:
	static constexpr int nMinesMax = 130;
	int nMines = 0;
	int mineCounter = 0;
	int newMine = 30;
	bool wasHit = false;
	Mine mine[nMinesMax];
};