
#include "PredBoid.h"

PredBoid::PredBoid(int id, sf::RenderWindow* window) : Boid(id, window), _window(window) {
    _bt = PREDATOR;
    _windowDimensions = _window->getSize();
    _pos = sf::Vector2f(rand() % _windowDimensions.x, rand() % _windowDimensions.y);
    _dir = VMath::resize(sf::Vector2f(2 * (rand() / (float)RAND_MAX) - 1, 2 * (rand() / (float)RAND_MAX) - 1), _maxVel);

    _mr = _windowDimensions.x - _ml;
    _mt = _ml;
    _mb = _windowDimensions.y - _ml;

    _sprite = sf::CircleShape(_boidSize);
    _sprite.setFillColor(sf::Color::Red);  // Color to distinguish PredBoid
}

void PredBoid::update(Boid** boids, int size) {
    sf::Vector2f closestBoidVector;
    float closestDist = std::numeric_limits<float>::max();

    for (int i = 0; i < size; i++)
    {
        // skip if self
        if (boids[i]->getId() == _id)
        {
            continue;
        }

        // get distance to boid
        float range = VMath::length(_pos - boids[i]->getPos());
        sf::Vector2f otherPos = boids[i]->getPos();
        float dist = VMath::length(otherPos - _pos);

        // act depending on the type of boid
        if (boids[i]->getBoidType() == PREY && dist < _visualRange) {
            // Chase logic 
            sf::Vector2f directionToPrey = boids[i]->getPos() - _pos;
            _vel += VMath::resize(directionToPrey, _maxVel); // Directly move towards prey
        }
        // Check for the closest boid within the warning range
        if (dist < warningRange && dist < closestDist) 
        {
            closestDist = dist;
            closestBoidVector = otherPos - _pos;
        }

        if (dist < _captureRange) 
        {
                // Simulate capture TODO
        }       

        // if (dist < _visualRange) {
        //     sf::Vector2f towards = otherPos - _pos;
        //     _dir += VMath::resize(towards, _maxVel);
        // }
    }

        // If a closest boid is found within the warning range, adjust the direction towards this boid
    if (closestDist < warningRange) {
        closestBoidVector = VMath::resize(closestBoidVector, _maxVel);
        _dir += closestBoidVector * approachFactor; // Use approachFactor to modulate the change in direction
    }

    normalizeVelocity();
    checkBounds();

    _pos += _dir; // Update position
    _sprite.setPosition(_pos);
}

void PredBoid::draw() {
    _window->draw(_sprite);
}

void PredBoid::checkBounds() {
    if (_pos.x < _ml || _pos.x > _mr) _dir.x = -_dir.x;
    if (_pos.y < _mt || _pos.y > _mb) _dir.y = -_dir.y;
}

void PredBoid::normalizeVelocity() {
    float length = VMath::length(_dir);
    if (length > _maxVel) {
        _dir = VMath::resize(_dir, _maxVel);
    } else if (length < _maxVel / 2) { // ensuring a minimum speed
        _dir = VMath::resize(_dir, _maxVel / 2);
    }
}
