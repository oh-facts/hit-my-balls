#include <Spawner.hpp>

Spawner::Spawner(Player *py, Player *py2, Football *fbl)
{
    this->m_py[0] = py;
    this->m_py[1] = py2;

    this->fb = fbl;

    m_pos[0] = py->getPos();
    m_pos[1] = py2->getPos();
    m_pos[2] = fbl->getPos();
}

void Spawner::update(float delta)
{
    checkCollision();

    if(isKeyHeld(sf::Keyboard::R) || fb->getPos().x>1000 || fb->getPos().x < -200)
    {
        reset();
    }
}

bool Spawner::checkCollision()
{
    for (int i = 0; i < 2; i++)
    {
        Player *py = m_py[i];
        if (py->getRect().getGlobalBounds().intersects(fb->getRect().getGlobalBounds()))
        {
            float slabPos = py->getPos().y; // Position of the slab
            float ballPos = slabPos - fb->getPos().y;

            sf::Vector2f initDir = fb->getDirection();

            sf::Vector2f resul = sf::Vector2f(-initDir.x, -(initDir.y + ballPos) / 100.f);

            float magnitude = std::sqrt(resul.x * resul.x + resul.y * resul.y);

            sf::Vector2f reflectedDir = (resul) / magnitude;

            fb->setDirection(reflectedDir);
            fb->stepVelocity();
            // The setting of the game is 1686
        }
    }

    if (fb->getPos().y > 590 || fb->getPos().y < 10)
    {
        sf::Vector2f poopdir = fb->getDirection();
        poopdir.y = -poopdir.y;
        fb->setDirection(poopdir);
        fb->stepVelocity();
    }

    return false;
}

void Spawner::reset()
{
 m_py[0]->setPos(m_pos[0]);
 m_py[1]->setPos(m_pos[1]);
 *fb = Football();
}
