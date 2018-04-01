#ifndef DS_RESOURCE_LOADER_HPP
#define DS_RESOURCE_LOADER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureLoader.hpp"
#include "FontLoader.hpp"

namespace ds {
    class ResourceLoader {
    private:
        TextureLoader textureLoader;
        FontLoader fontLoader;
    public:
        ResourceLoader();
        sf::Texture* getTexture(std::string path);
        sf::Font* getFont(std::string path);
    };
}

#endif // DS_RESOURCE_LOADER_HPP