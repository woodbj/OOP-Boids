#include "Predboid.h"

PredBoid::PredBoid(int id, sf::RenderWindow *window)
{
    // initialise variables
    _id = id;
    _window = window;
    _windowDimensions = _window->getSize();

    // initialise position
    _pos.x = rand() % _windowDimensions.x;
    _pos.y = rand() % _windowDimensions.y;
    _dir.x = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    _dir.y = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    float velocity = rand() / (1.f * RAND_MAX);
    VMath::scale(&_dir, velocity * _maxVel);

    // initialise boundaries
    _mr = _windowDimensions.x - _ml;
    _mt = _ml;
    _mb = _windowDimensions.y - _ml;

    // give a shape
    _sprite = sf::CircleShape(_boidSize);
}
