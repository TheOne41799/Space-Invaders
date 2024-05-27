#pragma once
#include <chrono>


class TimeService
{
private:
	std::chrono::time_point<std::chrono::steady_clock> previousTime;

	float deltaTime;

	void UpdateDeltaTime();
	float CalculateDeltaTime();
	void UpdatePreviousFrame();

public:
	void Initialize();
	void Update();

	float GetDeltaTime();
};
