
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "PredBoid.h" 
#include "PlayBoid.h"
class Controller : public PlayBoid
{
public:
    virtual sf::Vector2f steer();
    
private:
    
};

#endif // CONTROLLER_H