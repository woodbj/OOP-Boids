#include "VMath.h"

float VMath::length(Vector2f vector)
{
    
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

void VMath::scale(Vector2f *vector, float scale)
{
    *vector /= (float)sqrt(vector->x * vector->x + vector->y * vector->y);
    *vector *= scale;
}

Vector2f VMath::scale(Vector2f vector, float scale)
{
    vector /= (float)sqrt(vector.x * vector.x + vector.y * vector.y);
    vector *= scale;
    return vector;
}

Vector2f VMath::resize(Vector2f vector, float length)
{
    Vector2f out(0,0);
    if (vector.x == 0 && vector.y == 0) return out;
    float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
    vector /= magnitude;
    vector *= length;
    return vector;
}