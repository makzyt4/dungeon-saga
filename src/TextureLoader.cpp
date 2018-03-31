#include "../include/TextureLoader.hpp"

ds::TextureLoader::TextureLoader() {}

sf::Texture* ds::TextureLoader::getTexture(std::string path) {
    std::map<std::string, sf::Texture*>::iterator it = textureMap.find(path);
    sf::Texture* texture = new sf::Texture();

    if (it != textureMap.end()) {
        return it->second;
    } else if (!texture->loadFromFile(path.c_str())) {
        return NULL;
    }

    return texture;
}
