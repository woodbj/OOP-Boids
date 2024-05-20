#include "PredBoid.h"
#include "VMath.h"
#include <limits>
#include <cmath>

PredBoid::PredBoid(int id, sf::RenderWindow *window) : Boid(id, window) {
    _bt = PREDATOR;
    _sprite.setFillColor(sf::Color::Red);
}

void PredBoid::update(Boid **boids, int count) {
    Boid *closestPrey = findClosestPrey(boids, count);
    if (closestPrey) {
        moveToPrey(closestPrey);
    }

    // General update logic
    Boid::update(boids, count);
}

Boid *PredBoid::findClosestPrey(Boid **boids, int count) {
    Boid *closestPrey = nullptr;
    float minDistance = std::numeric_limits<float>::max();

    for (int i = 0; i < count; ++i) {
        Boid *prey = boids[i];
        if (prey->getBoidType() == PREY) {
            float distance = VMath::length(_pos - prey->getPos());
            if (distance < minDistance) {
                minDistance = distance;
                closestPrey = prey;
            }
        }
    }
    return closestPrey;
}

void PredBoid::moveToPrey(Boid *prey) {
    Vector2f direction = prey->getPos() - _pos;
    float length = VMath::length(direction);
    direction /= length; // Normalize the direction

    _vel += direction * _pf; // Adjust the velocity towards the prey

    // Limit velocity to max velocity
    if (VMath::length(_vel) > _maxVel) {
        _vel = VMath::resize(_vel, _maxVel);
    }
}
