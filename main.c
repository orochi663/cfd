#import "cfd.h"

int main(int argc, const char *argv[]) {

return 0;
}

void initAtPointWithVelocityAndMass(struct Particle *particle, struct Point p, struct Velocity v, float mass) {
(*particle).pos = p;
(*particle).vel = v;
(*particle).mass = mass;
}