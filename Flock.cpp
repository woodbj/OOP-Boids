#include "Flock.h"
#include "PredBoid.h"

Flock::Flock(FlockConfig fc, sf::RenderWindow *window)
{
    _size = fc.playCount + fc.predCount + fc.preyCount;
    _window = window;
    _boids = new Boid *[_size];

    int index = 0;  

    for (int i = 0; i < fc.predCount; i++, index++) {
        _boids[i] = new PredBoid(i, window); 
        std::cout << "Pred generate" << std::endl; 
    }

    for (int i = 0; i < fc.preyCount; i++, index++)
    {
        _boids[i] = new Boid(i, window);
        std::cout << "Prey generate" << std::endl; 
    }

}

void Flock::update()
{
    std::cout << "Updating flock with size: " << _size << std::endl;
    for (int i = 0; i < _size; i++)
    {
        std::cout << "Updating boid ID: " << i << std::endl;
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
