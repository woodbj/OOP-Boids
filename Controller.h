
    // Controller(/* args */);
    // virtual int steer() = 0;
    // ~Controller();


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Keyboard.h"
#include "PlayBoid.h"

class Controller : public Keyboard{
public:
    Controller();
    void handleInput();
    
private:
    
};

#endif // CONTROLLER_H