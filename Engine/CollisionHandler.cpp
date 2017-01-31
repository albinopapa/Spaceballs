#include "CollisionHandler.h"
#include "Bullet.h"
#include "Mine.h"
#include "Ship.h"


bool CollisionHandler::ShipVsMine( Ship & _Ship, Mine & _Mine )
{
	return _Ship.GetCollisionRect().Overlaps( _Mine.GetCollisionRect() );
}

bool CollisionHandler::BulletVsMine( Bullet & _Bullet, Mine & _Mine )
{
	return _Bullet.GetCollisionRect().Overlaps( _Mine.GetCollisionRect() );
}