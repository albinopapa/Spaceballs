#pragma once
#include "Graphics.h"
#include "Sound.h"
#include "Health.h"
#include "RectF.h"

class BulletManager;
class MainWindow;

class Ship
{
public:
	void Draw(Graphics& gfx);
	void Update( MainWindow& wnd, float dt, BulletManager& bm );
	void Restore(int restore);
	void Damage(int damage);

	bool HasHealth() const;
	float GetX()const;
	float GetY()const;
	float GetWidth()const;
	float GetHeight()const;
	bool hitTarget = false;

	RectF GetCollisionRect()const;
private:
	void FireBullet( BulletManager &bm );
	void ClampScreen();
	void PlayerInput( MainWindow& wnd, float dt, BulletManager& bm );
private:
	float x = 300.0f;
	float y = 300.0f;
	float width = 100.0f;
	float height = 100.0f;
	float canonPos = 50.0f;
	float vx = 6.0f * 60.0f;
	float vy = 6.0f * 60.0f;
	bool shotsFired = false;
	Sound gun = L"shitgun.wav";
	Health health;
	bool healthChanging = false;
	float padding = 35.0f;
};