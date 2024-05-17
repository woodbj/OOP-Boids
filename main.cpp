#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "Flock.h"
#include"PlayBoid.h"
#include <iostream>

int main()
{
    int w = 1920;
    int h = 1080;

    FlockConfig fc;
    fc.preyCount = 200;
    fc.predCount = 0;
    fc.playCount = 0;
    sf::CircleShape pl;
    sf::RenderWindow window(sf::VideoMode(w, h), "BOIDS!");
    Flock *flock = new Flock(fc, &window);
    sf::Event event;
    
PlayBoid P;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        flock->update();
        window.draw(P.set_player(pl));
        P.update(P.set_player(pl),&window);
        window.display();
    }

    delete flock;

    return 0;
}