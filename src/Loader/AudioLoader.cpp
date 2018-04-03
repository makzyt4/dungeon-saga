#include "../../include/Loader/AudioLoader.hpp"

sf::SoundBuffer* ds::AudioLoader::getSoundBuffer(std::string path) {
    path = "../../res/audio/" + path;
    std::map<std::string, sf::SoundBuffer*>::iterator it = audioMap.find(path);
    sf::SoundBuffer* buffer = new sf::SoundBuffer();

    if (it != audioMap.end()) {
        return it->second;
    } else if (!buffer->loadFromFile(path.c_str())) {
        return NULL;
    }

    audioMap.insert({path, buffer});
    return buffer;
}
