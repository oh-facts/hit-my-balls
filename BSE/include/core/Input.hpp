#ifndef INPUT_HPP

#define INPUT_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

bool isKeyHeld(sf::Keyboard::Key key);
bool isMouseButtonHeld(sf::Mouse::Button button);
#endif 
