#ifndef DS_SCENE_TESTSCENE_HPP
#define DS_SCENE_TESTSCENE_HPP

#include "Scene.hpp"
#include "../UI/Layout.hpp"
#include "../UI/Button.hpp"
#include "../Character/PlayerCharacter.hpp"

namespace ds {
    class TestScene : public Scene {
    private:
        Layout layout;
        Button button;
        PlayerCharacter player;
    public:
        using Scene::Scene;

        void init();
        void update();
        void control();
        void draw();
    };
}

#endif // DS_TESTSCENE_SCENE_HPP
