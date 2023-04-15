#include <Scene.hpp>
Scene::Scene(/* args */)
{
}

Scene::~Scene()
{
}

void Scene::addGameObject(Entity *gb)
{
    m_gb.push_back(gb);
}
void Scene::addSystem(Systems *sys)
{
    m_sys.push_back(sys);
}
void Scene::removeSystem(Systems *sys)
{

    for (auto it = m_sys.begin(); it != m_sys.end();)
    {
        Systems *item = *it;
        if (sys == item)
        {
            it = m_sys.erase(it);
            delete sys;
        }
        else
        {
            ++it;
        }
    }
}
void Scene::update(float delta)
{
    for (auto &gb : m_gb)
    {
        gb->update(delta);
    }
    for (auto &sys : m_sys)
    {
        sys->update(delta);
    }
}
void Scene::removeGameObject(Entity *gb)
{

    for (auto it = m_gb.begin(); it != m_gb.end();)
    {
        Entity *item = *it;
        if (gb == item)
        {
            it = m_gb.erase(it);
            delete gb;
        }
        else
        {
            ++it;
        }
    }
}
void Scene::render(Window &win)
{

    win.getWindow().clear();

    for (auto &gb : m_gb)
    {
        gb->render(win);
    }
    win.getWindow().display();
}

void Scene::copyFrom(const Scene other)
{
    // copy data from other to this scene...
    // example: copy a vector of objects
    m_gb = other.m_gb;
    m_sys = other.m_sys;
    printf("copy other data");
}
