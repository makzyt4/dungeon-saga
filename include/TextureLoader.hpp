#ifndef DS_TEXTURE_LOADER_HPP
#define DS_TEXTURE_LOADER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

namespace ds {
    class TextureLoader {
    private:
        std::map<std::string, sf::Texture*> textureMap;
    public:
        TextureLoader();
        sf::Texture* getTexture(std::string path);
    };
}

#endif // DS_TEXTURE_LOADER_HPP
