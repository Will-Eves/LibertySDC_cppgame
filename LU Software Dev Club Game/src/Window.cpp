#include "App.h"

namespace Window{
	sf::RenderWindow window;

	void Setup(int window_width = 1600, int window_height = 900, std::string window_name = "Window") {
		window.create(sf::VideoMode(window_width, window_height), window_name, sf::Style::Titlebar | sf::Style::Close);
	}

	void PollEvents() {
		// Poll all Window Events
		sf::Event event;
		while (window.pollEvent(event)) {
			// X Button on Window Clicked
			if (event.type == sf::Event::Closed) window.close();
		}
	}

	int clear_color_r = 0;
	int clear_color_g = 0;
	int clear_color_b = 0;
	void Clear() {
		window.clear(sf::Color(clear_color_r, clear_color_g, clear_color_b));
	}

	void SetClearColor(int r, int g, int b) {
		clear_color_r = r;
		clear_color_g = g;
		clear_color_b = b;
	}

	void Draw(sf::Drawable& drawable) {
		window.draw(drawable);
	}

	void Render() {
		window.display();
	}

	bool IsOpen(){
		return window.isOpen();
	}

	sf::RenderWindow* GetWindow() {
		return &window;
	}
}