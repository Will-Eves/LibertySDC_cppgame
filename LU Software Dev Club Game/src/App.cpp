#include "App.h"

namespace App{
	void Setup(int window_width, int window_height, std::string window_name) {
		Window::Setup(window_width, window_height, window_name);
		Time::Setup();

        // Load Audio
        Sound::LoadSound("explosion", "res/sounds/explosion.wav");

        // Load Font
        UI::LoadFont("SUSE", "res/fonts/SUSE-Light.ttf");

        // Load Texture
        Renderer::LoadSprite("wizard", "res/images/wizard.png", false);
	}

    double player_x = 0;
    double player_y = 0;
    bool flipped = false;

	void Refresh(){
		Time::Update();

		Window::PollEvents();

        // Sample Keyboard Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player_x -= 500 * Time::GetDeltaTime();
            flipped = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player_x += 500 * Time::GetDeltaTime();
            flipped = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player_y -= 500 * Time::GetDeltaTime();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player_y += 500 * Time::GetDeltaTime();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            Sound::PlaySound("explosion", true);
        }

        // Window Background Color
        Window::SetClearColor(150, 150, 175);
        Window::Clear();

        // Draw Sprite
        Renderer::DrawSprite("wizard", player_x, player_y, 64, 64, flipped);

        // Draw Text
        {
            UI::Style style;

            style.font = "SUSE";
            style.font_size = 100;

            style.background_color = sf::Color(200, 200, 200, 100);

            style.align_x = UI::Style::Middle;
            style.align_y = UI::Style::Center;

            style.border_style = UI::Style::Solid;
            style.border_color = sf::Color::Black;
            style.border_width = 4;

            style.padding_width = 8;

            UI::DrawText("Game", 800, 50, style);
        }

        {
            UI::Style style;

            style.width = 400;
            style.height = 150;

            style.background_color = sf::Color(200, 200, 200);

            style.align_x = UI::Style::Middle;
            style.align_y = UI::Style::Center;

            style.border_style = UI::Style::Solid;
            style.border_color = sf::Color::Black;
            style.border_width = 4;

            UI::Style hover_style;
            hover_style.Copy(style);

            hover_style.background_color = sf::Color(150, 150, 150);

            UI::Style click_style;
            click_style.Copy(hover_style);

            click_style.background_color = sf::Color(120, 120, 120);

            static int button_state = 0;
            if (UI::DrawButton(800, 450, style, hover_style, click_style)) {
                if (button_state == 0) {
                    button_state = 1;
                    std::cout << "Clicked!" << std::endl;
                }
            }
            else {
                button_state = 0;
            }
        }

        // Render Frame
        Window::Render();
	}

	bool IsRunning() {
		return Window::IsOpen();
	}
}