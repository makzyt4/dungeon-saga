#include "../include/SoundBufferLoader.hpp"

ds::SoundBufferLoader::SoundBufferLoader() {
    std::cout << "SoundBufferLoader :: Constructor\n";
}

sf::SoundBuffer* ds::SoundBufferLoader::getSoundBuffer(std::string path) {
    path = "../res/audio/" + path;
    std::map<std::string, sf::SoundBuffer*>::iterator it =
        soundBufferMap.find(path);
    sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();

    if (it != soundBufferMap.end()) {
        std::cout << "SoundBufferLoader :: Found sound buffer '"
                  << path << "'\n";
        return it->second;
    } else if (!soundBuffer->loadFromFile(path.c_str())) {
        std::cout << "SoundBufferLoader :: Could not load file '"
                  << path << "'\n";
        return NULL;
    }

    soundBufferMap.insert({path,soundBuffer});
    std::cout << "SoundBufferLoader :: Created new sound buffer from '"
              << path << "'\n";
    return soundBuffer;
}
