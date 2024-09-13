#include "App.h"

namespace Renderer {
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sprite> sprites;

    bool LoadSprite(std::string name, std::string file_path, bool smooth) {
        textures[name] = sf::Texture();
        if (!textures[name].loadFromFile(file_path /* Working dir seems to change depending on how its run */)) {
            std::cout << "ERROR: Could not load image." << std::endl;
        }
        textures[name].setSmooth(false); // False for pixel art, True for basically anything else
        // Create Sprite for Texture
        sprites[name] = sf::Sprite(textures[name]);
        // make sure to scale the sprite by its real w and h
        const int sprite_width = sprites[name].getTexture()->getSize().x;
        const int sprite_height = sprites[name].getTexture()->getSize().y;
        sprites[name].setScale(sf::Vector2f(1.0f / sprite_width * 64, 1.0f / sprite_height * 64));

        return true;
    }

    bool DrawSprite(std::string texture, int x, int y, int width, int height, bool flipped) {
        if (sprites.find(texture) == sprites.end()) {
            // TODO: Use a Default Texture

            return false;
        }

        const int sprite_width = sprites[texture].getTexture()->getSize().x;
        const int sprite_height = sprites[texture].getTexture()->getSize().y;
        sprites[texture].setScale(sf::Vector2f(1.0f / sprite_width * width, 1.0f / sprite_height * height));
        sprites[texture].setPosition(sf::Vector2f(x, y));

        if(flipped) sprites[texture].setTextureRect(sf::IntRect(sprite_width, 0, -sprite_width, sprite_height));
        else sprites[texture].setTextureRect(sf::IntRect(0, 0, sprite_width, sprite_height));
        
        Window::Draw(sprites[texture]);

        return true;
    }
}