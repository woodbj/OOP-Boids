
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/System/Vector2.hpp>
class Controller 
{
public:
    virtual sf::Vector2f steer(){} = 0;
    
private:
    
};

#endif // CONTROLLER_H