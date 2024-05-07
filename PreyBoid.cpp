#include "PreyBoid.h"

// https://people.ece.cornell.edu/land/courses/ece4760/labs/s2021/Boids/Boids.html#:~:text=Boids%20is%20an%20artificial%20life,very%20simple%20set%20of%20rules.

PreyBoid::PreyBoid(int id, sf::RenderWindow *window)
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

void PreyBoid::update(Vector2f *positions, Vector2f *velocities, BoidType* bt, int size)
{
    separation(positions, size);
    alignment(positions, velocities, size);
    cohesion(positions, size);

    

    margins();

    VMath::scale(&_dir, _maxVel);

    _pos += _dir;

    draw();
}

void PreyBoid::separation(Vector2f *positions, int size)
{
    Vector2f close;
    for (int i = 0; i < size; i++)
    {
        if (VMath::length(_pos - positions[i]) < _sr)
        {
            close += _pos - positions[i];
        }
        _dir += _sf * close;
    }
}

void PreyBoid::alignment(Vector2f *positions, Vector2f *vel, int size)
{
    if (!_align)
        return;
    Vector2f avgVel;
    int neighbours = 0;

    for (int i = 0; i < size; i++)
    {
        if (VMath::length(_pos - positions[i]) < _ar)
        {
            avgVel += vel[i];
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        avgVel /= (float)neighbours;
        _dir += (avgVel - _dir) * _af;
    }
}

void PreyBoid::cohesion(Vector2f *positions, int size)
{
    if (!_cohere)
        return;

    Vector2f avgPos;
    int neighbours = 0;

    for (int i = 0; i < size; i++)
    {
        if (VMath::length(_pos - positions[i]) < _cr)
        {
            avgPos += positions[i];
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        avgPos /= (float)neighbours;
        _dir += -(_pos - avgPos) * _cf;
    }
}

void PreyBoid::margins()
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

void PreyBoid::constrainPosition()
{

    if (_pos.x > _windowDimensions.x)
        _pos.x -= _windowDimensions.x;
    if (_pos.y > _windowDimensions.y)
        _pos.y -= _windowDimensions.y;
    if (_pos.x < 0)
        _pos.x += _windowDimensions.x;
    if (_pos.y < 0)
        _pos.y += _windowDimensions.y;
}

void PreyBoid::draw()
{
    _sprite.setPosition(_pos);
    _window->draw(_sprite);
}
