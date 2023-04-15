#ifndef SCENE_HPP
#define SCENE_HPP
#include <Gameobject.hpp>
#include <Systems.hpp>
#include <Window.hpp>
#include <vector>

class Scene
{
    private:
        std::vector<Entity *> m_gb;
        std::vector<Systems *> m_sys;
    public:
        Scene(/* args */);

        void addGameObject(Entity *);
        void addSystem(Systems *);

        void removeGameObject(Entity *);
        void removeSystem(Systems *);

        void update(float);

        void render(Window &);
        void copyFrom(const Scene other);
        ~Scene();
};

#endif
