#ifndef VMATH_H
#define VMATH_H

#include <cmath>
#include <SFML/System/Vector2.hpp>
using sf::Vector2f;

namespace VMath
{
    float length(Vector2f vector);
    void scale(Vector2f *vector, float scale);

};

#endif