#pragma once
#include <chrono>

class Timer {

public:
	Timer();
	void Run();
	float DeltaTime();
	float TimeFactor();

private:
	std::chrono::steady_clock::time_point last;
	float deltaTime;
	float timeFactor = 60.0f;

};