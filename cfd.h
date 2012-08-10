#import <stdio.h>
#import <stdlib.h>
#import <math.h>
#import <stdbool.h>

struct Pointf {
float x;
float y;
};

struct Particle {
bool isActive;
struct Pointf pos;
struct Pointf velocity;
};