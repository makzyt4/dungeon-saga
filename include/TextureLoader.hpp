#ifndef DS_RESOURCE_LOADER_HPP
#define DS_RESOURCE_LOADER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

namespace ds {
    class TextureLoader {
    private:
        std::map<std::string, sf::Texture*> textureMap;
    public:
        TextureLoader();
        sf::Texture* getTexture(std::string path);
    };
}

#endif
