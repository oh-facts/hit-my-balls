#ifndef FOOTBALL_HPP
#define FOOTBALL_HPP

#include <Gameobject.hpp>

class Football: public Gameobject<Ball>
{
private:
    sf::Vector2f dir;
    float velocity;

public:
    Football();
    void update(float) override;
    void setDirection(sf::Vector2f);
    void stepVelocity();
    sf::Vector2f getDirection();
    ~Football();
};

#endif