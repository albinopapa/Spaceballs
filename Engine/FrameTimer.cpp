#include "FrameTimer.h"
using namespace std::chrono;

FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

float FrameTimer::Mark()
{
#ifndef _DEBUG
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;

	return frameTime.count();
#else
	return 1.f / 60.f;
#endif;
}
