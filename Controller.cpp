#include "Controller.h"

Controller::Controller() {}

void Controller::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _sprite.move(0.f,-0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _sprite.move(0.f,0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _sprite.move(0.2f,0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _sprite.move(-0.2f,0.f);
    }
}