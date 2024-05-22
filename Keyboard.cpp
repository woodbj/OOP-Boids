#include "Keyboard.h"

Keyboard::Keyboard(){}
sf::Vector2f Keyboard::steer() {
    sf::Vector2f force(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
            force += sf::Vector2f(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
            force += sf::Vector2f(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
            force += sf::Vector2f(0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
            force += sf::Vector2f(0, 1);
    }
    return force;
};