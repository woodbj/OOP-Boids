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