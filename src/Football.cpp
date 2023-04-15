#include <Football.hpp>

Football::Football()
{
    set(sf::Vector2f(400.f, 300.f), 10.f, sf::Color::Blue);
    dir = sf::Vector2f(1.f, 0.f);
    velocity = 300.f;
}

Football::~Football()
{
}

void Football::update(float delta)
{
    move(dir.x*velocity * delta, dir.y*velocity*delta);
}

void Football::setDirection(sf::Vector2f a)
{
    dir = a;
}

void Football::stepVelocity()
{
    velocity+=100;
}

sf::Vector2f Football::getDirection(){return dir;}