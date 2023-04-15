#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <Input.hpp>
#include <Gameobject.hpp>

class Player : public Gameobject<Square>
{
    static int m_py;
    int this_py;
    sf::Keyboard::Key keys[2];
public:
    float m_velocity;
    void update(float delta) override;

    void stepVelocity();

    Player(sf::Color);

    ~Player();
};
#endif
