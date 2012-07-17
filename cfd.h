#import <stdio.h>
#import <math.h>

struct Vector {
float x,y;
}
struct Point {
float x,y;
}

struct Particle {
struct Point pos;  //position
struct Vector vel; //direction
float mass;
}

initAtPointWithVelocityAndMass(struct Particle *particle, struct Point p, struct Velocity v, float mass);
