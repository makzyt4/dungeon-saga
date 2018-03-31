#include "../include/TextureLoader.hpp"

ds::TextureLoader::TextureLoader() {
    std::cout << "TextureLoader :: Constructor\n";
}

sf::Texture* ds::TextureLoader::getTexture(std::string path) {
    std::map<std::string, sf::Texture*>::iterator it = textureMap.find(path);
    sf::Texture* texture = new sf::Texture();

    if (it != textureMap.end()) {
        std::cout << "TextureLoader :: Found texture '" << path << "'\n";
        return it->second;
    } else if (!texture->loadFromFile(path.c_str())) {
        std::cout << "TextureLoader :: Could not load file '" << path << "'\n";
        return NULL;
    }

    textureMap.insert({path,texture});
    std::cout << "TextureLoader :: Created new texture from '" << path << "'\n";
    return texture;
}
