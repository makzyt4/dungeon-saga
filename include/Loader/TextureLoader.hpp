#ifndef DS_LOADER_TEXTURELOADER_HPP
#define DS_LOADER_TEXTURELOADER_HPP

#include <map>
#include <SFML/Graphics.hpp>

namespace ds {
    class TextureLoader {
    private:
        std::map<std::string, sf::Texture*> textureMap;
    public:
        sf::Texture* getTexture(std::string path);
    };
}

#endif // DS_LOADER_TEXTURELOADER_HPP
