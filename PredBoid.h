
#ifndef PREDBOID_H
#define PREDBOID_H

#include "Boid.h"
#include "VMath.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include "DrawHelper.h"

#include "Boid.h"

class PredBoid : public Boid {
public:
    PredBoid(int id, sf::RenderWindow *window);

    virtual void update(Boid **boids, int count) override;

private:
    Boid *findClosestPrey(Boid **boids, int count);
    void moveToPrey(Boid *prey);
    virtual ~PredBoid() override;
};


#endif // PREDBOID_H
