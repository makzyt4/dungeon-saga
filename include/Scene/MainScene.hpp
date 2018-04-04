#ifndef DS_SCENE_MAINSCENE_HPP
#define DS_SCENE_MAINSCENE_HPP

#include "Scene.hpp"

namespace ds {
    class MainScene : public Scene {
    public:
        using Scene::Scene;

        void init();
        void update();
        void control();
        void draw();
    };
}

#endif // DS_MAINSCENE_SCENE_HPP
