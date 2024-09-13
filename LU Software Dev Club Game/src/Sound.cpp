#include "App.h"

namespace Sound {
	std::map<std::string, sf::SoundBuffer> buffers;
	std::map<std::string, sf::Sound> sounds;

	bool LoadSound(std::string name, std::string file_path) {
        buffers[name] = sf::SoundBuffer();
        if (!buffers[name].loadFromFile(file_path)) {
            std::cout << "ERROR: Could not load sound." << std::endl;

            return false;
        }
        // Create a Sound
        sounds[name] = sf::Sound();
        sounds[name].setBuffer(buffers[name]);

        return true;
	}

    bool PlaySound(std::string name, bool wait_if_playing) {
        if (sounds.find(name) != sounds.end()) {
            if (wait_if_playing && sounds[name].getStatus() == sf::Sound::Status::Playing) return false;

            sounds[name].play();

            return true;
        }
        else {
            return false;
        }
    }
}