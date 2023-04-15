#include <Input.hpp>

bool isKeyHeld(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool isMouseButtonHeld(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}