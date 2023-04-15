#include <Player.hpp>
Player::Player(sf::Color color)
{
	m_velocity = 600.0f;

	this_py = m_py;

	if (this_py == 0)
	{
		keys[0] = sf::Keyboard::W;
		keys[1] = sf::Keyboard::S;
		set(sf::Vector2f(20.f, 300.f), sf::Vector2f(10.f, 80.f), color);
	}

	if (this_py == 1)
	{
		keys[0] = sf::Keyboard::Up;
		keys[1] = sf::Keyboard::Down;
		set(sf::Vector2f(780.f, 300.f), sf::Vector2f(10.f, 80.f), color);
	}
	m_py++;

}
void Player::update(float delta)
{
	float velocity = m_velocity * delta;

	if (isKeyHeld(keys[0]))
	{
		move(0, -velocity);
	}
	if (isKeyHeld(keys[1]))
	{
		move(0, velocity);
	}
}

Player::~Player()
{
}
int Player::m_py = 0;