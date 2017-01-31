#include "RectF.h"



RectF::RectF()
{}

RectF::RectF( float X, float Y, float Width, float Height )
	:
	left( X ),
	top( Y ),
	right( X + Width ),
	bottom( Y + Height )
{}

float RectF::GetWidth() const
{
	return right - left;
}

float RectF::GetHeight() const
{
	return bottom - top;
}

bool RectF::Overlaps( const RectF & Rect ) const
{
	return ( left < Rect.right && right > Rect.left &&
			 top < Rect.bottom && bottom > Rect.top );
}
