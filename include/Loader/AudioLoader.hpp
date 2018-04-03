#ifndef DS_LOADER_AUDIOLOADER_HPP
#define DS_LOADER_AUDIOLOADER_HPP

#include <map>
#include <SFML/Audio.hpp>

namespace ds {
    class AudioLoader {
    private:
        std::map<std::string, sf::SoundBuffer*> audioMap;
    public:
        sf::SoundBuffer* getSoundBuffer(std::string path);
    };
}

#endif // DS_LOADER_AUDIOLOADER_HPP
