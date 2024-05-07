#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "Flock.h"

#include <iostream>

int main()
{
    int w = 1000;
    int h = 1000;

    FlockConfig fc;
    fc.preyCount = 100;
    fc.predCount = 0;
    fc.playCount = 0;

    sf::RenderWindow window(sf::VideoMode(w, h), "BOIDS!");
    Flock *flock = new Flock(fc, &window);
    sf::Event event;

    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        flock->update();
        window.display();
    }

    delete flock;

    return 0;
}