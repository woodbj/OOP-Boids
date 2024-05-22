
    // Controller(/* args */);
    // virtual int steer() = 0;
    // ~Controller();


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "PlayBoid.h"
#include "Flock.h"
#include "Boid.h"
#include "PredBoid.h" 

class Controller 
{
public:
    Controller();
    std::vector <float> steer();
    
private:
    
};

#endif // CONTROLLER_H