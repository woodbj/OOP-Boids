#ifndef VMATH_H
#define VMATH_H

#include <cmath>
#include <SFML/System/Vector2.hpp>
using sf::Vector2f;

class VMath
{
    public:
    static float length(Vector2f vector);
    static void scale(Vector2f *vector, float scale);
    static Vector2f resize(Vector2f vector, float length);

};

#endif