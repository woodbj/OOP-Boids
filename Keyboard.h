#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Window/Keyboard.hpp>
#include"Controller.h"
#include<vector>

class Keyboard : public Controller {
public:
    std::vector <float> steer();
};

#endif // KEYBOARD_H