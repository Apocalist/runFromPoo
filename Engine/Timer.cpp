#include "Timer.h"

using namespace std::chrono;


Timer::Timer()
{
	last = steady_clock::now();
}

void Timer::Run()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> timeCount = last - old;
	deltaTime =  timeCount.count();
}

float Timer::DeltaTime()
{
	return deltaTime *timeFactor;
}

float Timer::TimeFactor()
{
	return timeFactor;
}
