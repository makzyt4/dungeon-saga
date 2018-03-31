#include "../include/FontLoader.hpp"

ds::FontLoader::FontLoader() {
    std::cout << "FontLoader :: Constructor\n";
}

sf::Font* ds::FontLoader::getFont(std::string path) {
    path = "../res/fonts/" + path;
    std::map<std::string, sf::Font*>::iterator it = fontMap.find(path);
    sf::Font* font = new sf::Font();

    if (it != fontMap.end()) {
        std::cout << "FontLoader :: Found font '" << path << "'\n";
        return it->second;
    } else if (!font->loadFromFile(path.c_str())) {
        std::cout << "FontLoader :: Could not load file '" << path << "'\n";
        return NULL;
    }

    fontMap.insert({path,font});
    std::cout << "FontLoader :: Created new font from '" << path << "'\n";
    return font;
}
