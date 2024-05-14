
#include "PredBoid.h"

PredBoid::PredBoid(int id, sf::RenderWindow* window) : Boid(id, window), _window(window) {
    std::cout << "PredBoid constructed with ID " << id << std::endl;
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
    sf::Vector2f closestVector;
    float closestDist = std::numeric_limits<float>::max();

    std::cout << "Updating PredBoid ID " << _id << std::endl;

    for (int i = 0; i < size; i++) {
        if (boids[i]->getId() == _id) continue; // Skip self

        float dist = VMath::length(_pos - boids[i]->getPos());

        // Log distance to each boid
        std::cout << "Distance to Boid ID " << boids[i]->getId() << ": " << dist << std::endl;

        if (boids[i]->getBoidType() == PREY && dist < closestDist) {
            closestDist = dist;
            closestVector = boids[i]->getPos() - _pos;
            std::cout << "New closest prey found at distance: " << dist << std::endl;
        }
    }

    if (closestDist < _visualRange) {
        _vel += VMath::resize(closestVector, _maxVel);
        std::cout << "Chasing closest prey at vector: (" << closestVector.x << ", " << closestVector.y << ") with velocity change to: (" << _vel.x << ", " << _vel.y << ")" << std::endl;
    } else {
        std::cout << "No prey within visual range." << std::endl;
    }

    normalizeVelocity();
    checkBounds();

    _pos += _vel;  // Update position
    _sprite.setPosition(_pos);
}

void PredBoid::draw() {
    _sprite.setPosition(_pos);
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
    } else if (length < _maxVel / 2) {  // ensuring a minimum speed
        _dir = VMath::resize(_dir, _maxVel / 2);
    }
}
