#include "BulletManager.h"
#include "CollisionHandler.h"

BulletManager::BulletManager()
{}

BulletManager::~BulletManager()
{}

void BulletManager::SpawnBullet( float X, float Y )
{
	bullet[ bulletCounter ].Spawn( X, Y );
	++bulletCounter;
	if( bulletCounter > 2 )
	{
		bulletCounter = 0;
	}
}

void BulletManager::KillBullet( int Idx )
{
	for( int i = Idx; i < bulletCounter - 1; ++i )
	{
		bullet[ i ] = bullet[ i + 1 ];
	}
	--bulletCounter;
	if( bulletCounter < 0 ) bulletCounter = 0;
}

void BulletManager::UpdateBullets( float Dt )
{
	for( int i = 0; i < bulletCounter; ++i )
	{
		bullet[ i ].Update( Dt );
	}
}

Bullet* BulletManager::GetBullets()
{
	return bullet;
}

int BulletManager::GetnBullets()
{
	return bulletCounter;
}

void BulletManager::DrawBullets( Graphics & gfx )
{
	for( int i = 0; i < bulletCounter; ++i )
	{
		bullet[ i ].Draw( gfx );
	}
}

