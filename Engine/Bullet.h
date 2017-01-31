#pragma once

#include "Graphics.h"
#include "RectF.h"

class Bullet
{
public:
	void Spawn( float X, float Y );
	void Update(float dt);
	bool HasSpawned() const;
	void Draw(Graphics & gfx);
	float GetX()const;
	float GetY()const;
	int GetBulletSize()const;
	RectF GetCollisionRect()const;
private:
	bool hasSpawned = false;
	int bulletSize = 10;
	float x;
	float y;
	float vy = 15.0f * 60.0f;
};