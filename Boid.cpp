#include "Boid.h"

// https://people.ece.cornell.edu/land/courses/ece4760/labs/s2021/Boids/Boids.html#:~:text=Boids%20is%20an%20artificial%20life,very%20simple%20set%20of%20rules.

Boid::Boid(int id, sf::RenderWindow *window)
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

void Boid::update(Boid** boids, int size)
{
    Vector2f separation;
    Vector2f alignment;
    Vector2f cohesion;
    Vector2f predator;

    int alignmentNeighbours = 0;
    int cohesionNeighbours = 0;

    // loop through all other boids
    for (int i = 0; i < size; i++)
    {   
        if (boids[i]->getId() == _id)
        {
            continue;
        }

        float range = VMath::length(_pos - boids[i]->getPos());

        // act depending on the type of boid
        switch (boids[i]->getBoidType())
        {
        case PREY:
            // Separation
            if (range < _sr)
            {
                separation += _pos - boids[i]->getPos();
            }
            // Alignment
            if (range < _ar)
            {
                alignment += boids[i]->getVel();
                alignmentNeighbours++;
            }
            // Cohesion
            if (range < _cr)
            {
                cohesion += boids[i]->getPos();
                cohesionNeighbours++;
            }
            break;

        case PREDATOR:
            if (range < _pr)
            {
                predator -= _pos - boids[i]->getPos();
            }
            break;
        }
    }

    // apply the velocity changes
    _dir += _sf * separation;
    _dir += _pf * predator;

    if (alignmentNeighbours > 0)
    {
        alignment /= (float)alignmentNeighbours;
        _dir += (alignment - _dir) * _af;
    }

    if (cohesionNeighbours > 0)
    {
        cohesion /= (float)cohesionNeighbours;
        _dir += -(_pos - cohesion) * _cf;
    }

    // keep the boids within the margins
    margins();

    // scale the vector to be within the max velocity
    VMath::scale(&_dir, _maxVel);

    // move and draw the boid
    _pos += _dir;
    draw();
}

void Boid::margins()
{
    if (_pos.x < _ml)
        _dir.x += _tf;
    if (_pos.x > _mr)
        _dir.x -= _tf;
    if (_pos.y > _mb)
        _dir.y -= _tf;
    if (_pos.y < _mt)
        _dir.y += _tf;
}

void Boid::draw()
{
    _sprite.setPosition(_pos);
    _window->draw(_sprite);
}

Boid::~Boid()
{
    std::cout << "Deleting boid id " << _id << '\n';
}