#pragma once

#include "Bullet.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void SpawnBullet( float X, float Y );
	void KillBullet( int Idx );
	void UpdateBullets( float Dt );
	void DrawBullets( class Graphics &gfx );

	Bullet* GetBullets();
	int GetnBullets();
private:
	static constexpr int nBullets = 3;
	int bulletCounter = 0;
	Bullet bullet[ nBullets ];

};

