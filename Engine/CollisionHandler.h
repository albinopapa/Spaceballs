#pragma once
class CollisionHandler
{
public:
	static bool ShipVsMine( class Ship &_Ship, class Mine &_Mine );
	static bool BulletVsMine( class Bullet &_Bullet, class Mine &_Mine );
};

