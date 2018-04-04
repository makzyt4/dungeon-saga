#ifndef DS_MAIN_MAIN_HPP
#define DS_MAIN_MAIN_HPP

#include <SFML/Graphics.hpp>
#include "../../include/Loader/ResourceLoader.hpp"
#include "../../include/Scene/TestScene.hpp"
#include "../../include/Util/Settings.hpp"

namespace ds {
    class Main {
    private:
        Settings settings;

    public:
        Main();
    };
}

#endif // DS_MAIN_MAIN_HPP
