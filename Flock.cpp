#include "Flock.h"

Flock::Flock(FlockConfig fc, sf::RenderWindow *window)
{
    _size = fc.playCount + fc.predCount + fc.preyCount;
    _window = window;
    _boids = new Boid *[_size];

    for (int i = 0; i < fc.preyCount; i++)
    {
        _boids[i] = new Boid(i, window);
    }
}

void Flock::update()
{
    for (int i = 0; i < _size; i++)
    {
        _boids[i]->update(_boids, _size);
    }
}

Flock::~Flock()
{
    for (int i = 0; i < _size; i++)
    {
        delete _boids[i];
    }
}
