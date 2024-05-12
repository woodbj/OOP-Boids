#include "Boid.h"

// https://people.ece.cornell.edu/land/courses/ece4760/labs/s2021/Boids/Boids.html#:~:text=Boids%20is%20an%20artificial%20life,very%20simple%20set%20of%20rules.

Boid::Boid(int id, sf::RenderWindow *window)
{
    // initialise variables
    _id = id;
    _window = window;
    _windowDimensions = _window->getSize();
    dh = new DrawHelper(_window);

    // initialise position
    _pos.x = rand() % _windowDimensions.x;
    _pos.y = rand() % _windowDimensions.y;
    _vel.x = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    _vel.y = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    float velocity = rand() / (1.f * RAND_MAX);
    VMath::scale(&_vel, velocity * _maxVel);

    // initialise boundaries
    _mr = _windowDimensions.x - _ml;
    _mt = _ml;
    _mb = _windowDimensions.y - _ml;

    // give a shape
    _sprite = sf::CircleShape(_boidSize);

    if(_id == 0)
    {
        _sprite.setFillColor(sf::Color::Magenta);
    }
}

void Boid::update(Boid** boids, int size)
{
    Vector2f separation;
    Vector2f alignment;
    Vector2f cohesion;
    Vector2f predator;

    Vector2f av;
    Vector2f cv;
    Vector2f sv;
    Vector2f pv;

    int alignmentNeighbours = 0;
    int cohesionNeighbours = 0;

    // loop through all other boids
    for (int i = 0; i < size; i++)
    {   
        // skip if self
        if (boids[i]->getId() == _id)
        {
            continue;
        }

        // get distance to boid
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
    sv = _sf * separation;
    pv = _pf * predator;

    if (alignmentNeighbours > 0)
    {
        alignment /= (float)alignmentNeighbours;
        av = (alignment) * _af;
    }

    if (cohesionNeighbours > 0)
    {
        cohesion /= (float)cohesionNeighbours;
        cv = -(_pos - cohesion) * _cf;
    }

    if (_id == 0)
    {
        dh->drawCircle(_pos, _visualRange, _boidSize);
        dh->drawCircle(_pos, _personalSpace, _boidSize);

        Vector2f separate = sv / _sf;
        Vector2f align = 50.f * av / _af;
        Vector2f cohere = cv / _cf;
        
        dh->drawVelocity(_pos, separate, sf::Color::Blue, _boidSize);
        dh->drawVelocity(_pos, align, sf::Color::Red, _boidSize);
        dh->drawVelocity(_pos, cohere, sf::Color::Green, _boidSize);
    }

    // keep the boids within the margins
    margins();

    // scale the vector to be within the max velocity
    _vel += av + cv + sv;
    VMath::scale(&_vel, _maxVel);
    _pos += _vel;

    // move and draw the boid
    draw();
}

void Boid::margins()
{
    if (_pos.x < _ml)
        _vel.x += _tf;
    if (_pos.x > _mr)
        _vel.x -= _tf;
    if (_pos.y > _mb)
        _vel.y -= _tf;
    if (_pos.y < _mt)
        _vel.y += _tf;
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