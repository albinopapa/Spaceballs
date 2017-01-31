#pragma once


class RectF
{
public:
	RectF();
	RectF( float X, float Y, float Width, float Height );

	float GetWidth()const;
	float GetHeight()const;
	bool Overlaps( const RectF &Rect )const;

	float left = 0.f, top = 0.f, right = 0.f, bottom = 0.f;
};

