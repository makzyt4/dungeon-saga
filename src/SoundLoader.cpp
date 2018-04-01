#include "../include/SoundLoader.hpp"

ds::SoundLoader::SoundLoader() {
    std::cout << "SoundLoader :: Constructor\n";
}

sf::SoundBuffer* ds::SoundLoader::getSoundBuffer(std::string path) {
    path = "../res/audio/" + path;
    std::map<std::string, sf::SoundBuffer*>::iterator it = soundMap.find(path);
    sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();

    if (it != soundMap.end()) {
        std::cout << "SoundLoader :: Found sound buffer '" << path << "'\n";
        return it->second;
    } else if (!soundBuffer->loadFromFile(path.c_str())) {
        std::cout << "SoundLoader :: Could not load file '" << path << "'\n";
        return NULL;
    }

    soundMap.insert({path,soundBuffer});
    std::cout << "SoundLoader :: Created new sound buffer from '"
              << path << "'\n";
    return soundBuffer;
}
