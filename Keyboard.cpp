#include "Keyboard.h"

bool Keyboard::isKeyPressed(sf::Keyboard::Key key) {
}
sf::Vector2f Keyboard::steer(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        return -0.2f,0.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        return 0.2f,0.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        return 0.f,-0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        return 0.f,0.2f;
    }
}