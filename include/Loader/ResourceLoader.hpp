#ifndef DS_LOADER_RESOURCELOADER_HPP
#define DS_LOADER_RESOURCELOADER_HPP

#include "AudioLoader.hpp"
#include "TextureLoader.hpp"

namespace ds {
    class ResourceLoader {
    private:
        AudioLoader audioLoader;
        TextureLoader textureLoader;
    public:
        sf::SoundBuffer* getSoundBuffer(std::string path);
        sf::Texture* getTexture(std::string path);
    };
}

#endif // DS_LOADER_RESOURCELOADER_HPP
