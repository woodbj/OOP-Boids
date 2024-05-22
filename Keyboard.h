#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Window/Keyboard.hpp>

class Keyboard {
public:
    static bool isKeyPressed(sf::Keyboard::Key key);
    virtual int steer();
};

#endif // KEYBOARD_H