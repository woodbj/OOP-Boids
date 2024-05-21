#include "Flock.h"
#include "PredBoid.h"
#include "PlayBoid.h"

Flock::Flock(FlockConfig fc, sf::RenderWindow *window)
{
    _size = fc.playCount + fc.predCount + fc.preyCount;
    _window = window;
    _boids = new Boid *[_size];

    int id = 0;

    // Create PreyBoids
    for (int i = 0; i < fc.preyCount; i++)
    {
        _boids[id++] = new Boid(id, window);
    }

    // Create PredBoids
    for (int i = 0; i < fc.predCount; i++)
    {
        _boids[id++] = new PredBoid(id, window);
    }

    for (int i = 0; i < fc.playCount; i++)
    {
        _boids[id++] = new PlayBoid(id, window);
    }
}

void Flock::update()
{
    for (int i = 0; i < _size; i++)
    {
        if (_boids[i] != nullptr)
        {
            _boids[i]->update(_boids, _size);
        }
        else
        {
            std::cout << "Null pointer found at index " << i << std::endl;
        }
    }
}

Flock::~Flock()
{
    for (int i = 0; i < _size; i++)
    {
        delete _boids[i];
    }
}
