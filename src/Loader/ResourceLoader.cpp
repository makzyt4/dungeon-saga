#include "../../include/Loader/ResourceLoader.hpp"

sf::SoundBuffer* ds::ResourceLoader::getSoundBuffer(std::string path) {
    return audioLoader.getSoundBuffer(path);
}

sf::Texture* ds::ResourceLoader::getTexture(std::string path) {
    return textureLoader.getTexture(path);
}
