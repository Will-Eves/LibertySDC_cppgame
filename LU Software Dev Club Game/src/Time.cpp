#include "App.h"

namespace Time {
	std::chrono::steady_clock::time_point last_time;

	double delta_time;

	void Setup() {
		last_time = std::chrono::high_resolution_clock::now();
		delta_time = 0.0;
	}

	void Update() {
		auto current_time = std::chrono::high_resolution_clock::now();
		delta_time = std::chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count() / 1000000.0;
		last_time = current_time;
	}

	double GetDeltaTime() {
		return delta_time;
	}
}