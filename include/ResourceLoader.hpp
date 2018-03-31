#ifndef DS_RESOURCE_LOADER_HPP
#define DS_RESOURCE_LOADER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureLoader.hpp"

namespace ds {
    class ResourceLoader {
    private:
        TextureLoader textureLoader;
    public:
        ResourceLoader();
        sf::Texture* getTexture(std::string path);
    };
}

#endif // DS_RESOURCE_LOADER_HPP
