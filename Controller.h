
    // Controller(/* args */);
    // virtual int steer() = 0;
    // ~Controller();


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Keyboard.h"
#include "PlayBoid.h"
#include "Flock.h"
#include "Boid.h"
#include "PredBoid.h" 

class Controller : public PlayBoid{
public:
    Controller();
    void handleInput();
    
private:
    
};

#endif // CONTROLLER_H