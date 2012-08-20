#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct Pointf {
float x;
float y;
};

struct Particle {
bool isActive;
struct Pointf pos;
struct Pointf velocity;
};
