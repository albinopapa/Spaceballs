#pragma once
#include "Graphics.h"
#include "Health.h"
#include "RectF.h"
#include "Sound.h"

class Mine
{
public:
	void Update(class Ship& ship, float dt);
	void Draw(Graphics& gfx,class Ship& ship);
	void SetPos(float X);
	bool isActive();
	bool IsAlive();
	void Detonate();
	RectF GetCollisionRect()const;
	int GetDamage()const;
private:
	float x = 0.0f;
	float y = -50.0f;
	float vy = 5.0f * 60.0f;
	int explosionCounter = 0;
	static constexpr int explosionEnd = 30;
	bool isDetonated = false;
	bool gotPosition = false;
	static constexpr int damage = 75;
	static constexpr float width = 50.0f;
	static constexpr float height = 50.0f;
	bool isDamaged = false;
	Sound explosion = L"explo.wav";
};