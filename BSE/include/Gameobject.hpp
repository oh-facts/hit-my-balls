#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <Entity.hpp>

struct Square
{
    /* data */
};

struct Ball
{
    /* data */
};

template <typename T>
class Gameobject : public Entity
{
    static_assert(std::is_same<T, Ball>::value || std::is_same<T, Square>::value,
                  "Item template argument must be Ball or Square");
};

template <>
class Gameobject<Ball> : public Entity
{
private:
    sf::CircleShape m_shape;

public:
    Gameobject()
    {
        m_shape.setRadius(10.f);
        m_shape.setFillColor(sf::Color::Red);
    }
    Gameobject(sf::Vector2f pos, float radius, sf::Color color)
    {
        m_shape.setRadius(radius);
        m_shape.setFillColor(color);
        m_shape.setPosition(pos);
    }
    void set(sf::Vector2f pos, float radius, sf::Color color)
    {
        m_shape.setRadius(radius);
        m_shape.setFillColor(color);
        m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
        m_shape.setPosition(pos);
    }
    void render(Window &window) override
    {
        window.getWindow().draw(m_shape);
    }
    void move(float x, float y)
    {
        m_shape.move(x, y);
    }
    void setPos(sf::Vector2f pos)
    {
        m_shape.setPosition(pos);
    }
    void destroy()
    {
        delete this;
    }
    /* bool checkCollision(Entity *other)
     {
         //return m_shape.getGlobalBounds().intersects(other->getRect().getGlobalBounds());
     }*/
    sf::CircleShape getRect() { return m_shape; }
    sf::Vector2f getPos() { return m_shape.getPosition(); }
    ~Gameobject(){};
};

template <>
class Gameobject<Square> : public Entity
{
private:
    sf::RectangleShape m_shape;

public:
    Gameobject()
    {
        m_shape.setSize(sf::Vector2f(20.f, 20.f));
        m_shape.setFillColor(sf::Color::Red);
    }
    void set(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
    {
        m_shape.setSize(size);
        m_shape.setFillColor(color);

        m_shape.setOrigin(m_shape.getSize() / 2.0f); // set the origin to the center of the rectangle

        m_shape.setPosition(pos);
    }
    void render(Window &window) override
    {
        window.getWindow().draw(m_shape);
    }
    void move(float x, float y)
    {
        m_shape.move(x, y);
    }
    sf::Vector2f getPos()
    {
        return m_shape.getPosition();
    }
    sf::RectangleShape getRect() { return m_shape; }
    void destroy()
    {
        delete this;
    }

    void setPos(sf::Vector2f pos)
    {
        m_shape.setPosition(pos);
    }
    /* bool checkCollision(Entity *other)
     {
         return m_shape.getGlobalBounds().intersects(other->getRect().getGlobalBounds());
     }*/
    ~Gameobject(){};
};

#endif
