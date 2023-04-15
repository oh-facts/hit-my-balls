#ifndef ENTITY_HPP
#define ENTITY_HPP

#include<Window.hpp>

class Entity
{
public:
    virtual void update(float delta){};
    virtual void render(Window &window){};
};
#endif