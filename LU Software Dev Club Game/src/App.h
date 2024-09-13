#include <iostream>
#include <chrono>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Window.h"
#include "Sound.h"
#include "UI.h"
#include "Renderer.h"
#include "Time.h"

namespace App {
	void Setup(int window_width=1600, int window_height=900, std::string window_name="Window");
	void Refresh();

	bool IsRunning();
}