#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Window/Keyboard.hpp>
#include "Controller.h"
#include <vector>
#include"PlayBoid.h"

class Keyboard : public Controller
{
public:
    Keyboard();
    sf::Vector2f steer();
};
#endif // KEYBOARD_H