#include "App.h"

namespace UI {
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Text> texts;

    void Style::Copy(Style& other) {
        this->color = other.color;
        this->text_style = other.text_style;
        this->font = other.font;
        this->font_size = other.font_size;

        this->background_color = other.background_color;

        this->align_x = other.align_x;
        this->align_y = other.align_y;

        this->width = other.width;
        this->height = other.height;

        this->border_style = other.border_style;
        this->border_width = other.border_width;
        this->border_color = other.border_color;

        this->padding_width = other.padding_width;
    }

	bool LoadFont(std::string name, std::string file_path) {
        fonts[name] = sf::Font();
        if (!fonts[name].loadFromFile(file_path)) {
            std::cout << "ERROR: Could not load font." << std::endl;

            return false;
        }
        // Create Text for Font
        texts[name] = sf::Text();
        texts[name].setFont(fonts[name]);

        return true;
	}

    bool DrawText(std::string text_to_write, int x, int y, Style& style) {
        if (texts.find(style.font) == texts.end()) {
            // TODO: Use a Default Font

            return false;
        }

        sf::Text& text = texts[style.font];

        text.setCharacterSize(style.font_size);
        text.setFillColor(style.color);
        text.setStyle(style.text_style);

        style.width = text.getLocalBounds().getSize().x;
        style.height = text.getLocalBounds().getSize().y;

        sf::Vector2f origin = sf::Vector2f(text.getLocalBounds().getPosition());
        if (style.align_x == UI::Style::Middle) origin.x += text.getLocalBounds().getSize().x / 2;
        else if(style.align_x == UI::Style::Right) origin.x += text.getLocalBounds().getSize().x;
        if (style.align_y == UI::Style::Center) origin.y += text.getLocalBounds().getSize().y / 2;
        else if (style.align_y == UI::Style::Bottom) origin.y += text.getLocalBounds().getSize().y;
        text.setOrigin(origin);

        sf::Vector2f position = sf::Vector2f(x, y);
        if (style.align_x == UI::Style::Left) position.x += style.padding_width;
        else if (style.align_x == UI::Style::Right) position.x -= style.padding_width;
        if (style.align_y == UI::Style::Top) position.y += style.padding_width;
        else if (style.align_y == UI::Style::Bottom) position.y -= style.padding_width;
        text.setPosition(position);

        text.setString(text_to_write);
        DrawPanel(x, y, style);
        Window::Draw(text);

        return true;
    }

    sf::RectangleShape CreateRect(int x, int y, Style& style) {
        sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(style.width + style.padding_width * 2, style.height + style.padding_width * 2));

        rectangle.setFillColor(style.background_color);
        rectangle.setPosition(sf::Vector2f(x, y));

        if (style.border_style == Style::Solid) {
            rectangle.setOutlineColor(style.border_color);
            rectangle.setOutlineThickness(style.border_width);
        }

        if (style.align_x == Style::Middle) rectangle.move(sf::Vector2f(-(style.width + style.padding_width * 2) / 2, 0));
        else if (style.align_x == Style::Right) rectangle.move(sf::Vector2f(-(style.width + style.padding_width * 2), 0));
        if (style.align_y == Style::Center) rectangle.move(sf::Vector2f(0, -(style.height + style.padding_width * 2) / 2));
        else if (style.align_y == Style::Bottom) rectangle.move(sf::Vector2f(0, -(style.height + style.padding_width * 2)));

        return rectangle;
    }

    bool DrawPanel(int x, int y, Style& style) {
        sf::RectangleShape rect = CreateRect(x, y, style);

        Window::Draw(rect);

        rect.~RectangleShape();

        return true;
    }

    bool DrawButton(int x, int y, Style& style, Style& hover_style, Style& click_style) {
        // if clicked return true
        sf::Vector2i globalPosition = sf::Mouse::getPosition();
        sf::Vector2i localPosition = sf::Mouse::getPosition(*Window::GetWindow());

        sf::RectangleShape rect = CreateRect(x, y, style);

        sf::Vector2f size = rect.getSize();
        sf::Vector2f pos = rect.getPosition();

        // check mouse hover button
        if (localPosition.x > pos.x && localPosition.x < pos.x + size.x && localPosition.y > pos.y && localPosition.y < pos.y + size.y) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                DrawPanel(x, y, click_style);

                rect.~RectangleShape();

                return true;
            }
            else {
                DrawPanel(x, y, hover_style);
            }
        }
        else {
            DrawPanel(x, y, style);
        }

        rect.~RectangleShape();

        return false;
    }
}