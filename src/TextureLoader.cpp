#include "../include/TextureLoader.hpp"

ds::TextureLoader::TextureLoader() {}

sf::Texture* ds::TextureLoader::getTexture(std::string path) {
    std::map<std::string, sf::Texture*>::iterator it = textureMap.find(path);
    sf::Texture* texture = new sf::Texture();

    if (it != textureMap.end()) {
        std::cout << ""
        std::cout << "TextureLoader :: Found file '" << path << "'\n"
        return it->second;
    } else if (!texture->loadFromFile(path.c_str())) {
        std::cout << "TextureLoader :: Could not load file '" << path << "'\n";
        return NULL;
    }

    std::cout << "TextureLoader :: Created new texture from '" << path << "'\n";
    return texture;
}
