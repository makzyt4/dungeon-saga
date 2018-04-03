#include "../include/ResourceLoader.hpp"

ds::ResourceLoader::ResourceLoader() {
    std::cout << "ResourceLoader :: Constructor\n";
}

sf::Texture* ds::ResourceLoader::getTexture(std::string path) {
    return textureLoader.getTexture(path);
}

sf::SoundBuffer* ds::ResourceLoader::getSoundBuffer(std::string path) {
    return soundLoader.getSoundBuffer(path);
}
