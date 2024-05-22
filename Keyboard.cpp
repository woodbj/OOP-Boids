#include "Keyboard.h"


sf::Vector2f Keyboard::steer(){
    sf::Vector2f force(0, 0);

std::vector<sf::Vector2f> a;   a.resize(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
            force += sf::Vector2f(-1, 0);
        return force;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
            force += sf::Vector2f(1, 0);
        return force;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
            force += sf::Vector2f(0, -1);
        return force;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
            force += sf::Vector2f(0, 1);
        return force;
    }
};