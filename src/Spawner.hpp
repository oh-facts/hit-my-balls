#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <Football.hpp>
#include <Player.hpp>
#include <Scene.hpp>
#include <Systems.hpp>
#include<cmath>

class Spawner : public Systems
{
private:

    Player* m_py[2];
    Football *fb;
    bool flag = false;
    sf::Vector2f m_pos[3];
    
public:
    Spawner(Player*,Player*,Football*);
    void reset();
    void update(float delta) override;
    bool checkCollision();
};
// Header file code goes here

#endif
