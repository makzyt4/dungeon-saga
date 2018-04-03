#ifndef DS_SCENE_SCENE_HPP
#define DS_SCENE_SCENE_HPP

#include <SFML/Graphics.hpp>
#include "../Enum/ExitCode.hpp"
#include "../Interface/Controllable.hpp"
#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"
#include "../Loader/ResourceLoader.hpp"

namespace ds {
    class Scene
        : public Controllable,
          public Drawable,
          public Updatable {
    protected:
        sf::RenderWindow* window;
        ResourceLoader* loader;
        ExitCode code;

    public:
        Scene(sf::RenderWindow* window, ResourceLoader* loader);

        ExitCode getCode() const;

        void generateView();
        void generateView(sf::Vector2i center);

        virtual void init() = 0;
    };
}

#endif // DS_SCENE_SCENE_HPP
