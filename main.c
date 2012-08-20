/* -------------------------
// ----------TODO-----------
// USE ENVX AND ENVY VARS!!!
// NEED UNIVERSAL VALUES
// CREATE SCALING MECHANISM
// ----------TODO-----------
*///-----------------------

#include "cfd.h"

int main(int argc, const char *argv[]) {
	//Split up env into evenly sized blocks
	int envX = 100;
	int envY = 100;
	float env[envX][envY];

	//Create particles
	int numParticles = 10;
	struct Particle *p;
	struct Particle particles[numParticles];

	printf("allocated particles\n");

	//initialize particles
	/*
	int j;
	for(j = 0; j <= numParticles; j++) {
		p = &particles[j];
	}
	*/

	// go through each particle and sum
	// a 'force map' of size a where a is
	// odd, with env at particle location.
	// fmap must be in one block.
	// currently only supports square fmaps.
	// void fmapSetup(float *fmap, size);
	int fSize = 7;
	float fmap[fSize][fSize];
	//fmapSetup(fmap,fSize);

	//struct Particle *p;
	int fcount;
	int mx,my;
	int pNum;
	for(pNum = 0; pNum < numParticles; pNum++) {
		p = &particles[pNum];
		if (p->isActive) {
			fcount = 0;
			for(mx = (int)(p->pos.x)-(fSize-1)/2; mx <= (int)(p->pos.x)+(fSize-1)/2; mx++) {
				for(my = (int)(p->pos.y)-(fSize-1)/2; my <= (int)(p->pos.y)+(fSize-1)/2; my++) {
					if (mx > 0 && mx < envX && my > 0 && my < envY) {
						env[mx][my] += fmap[0][fcount++];
					} else {
						fcount++;
					}
				}
			}
		}
	}

	printf("created force map\n");

	//Set up time for integration
	float lastTime;
	float timeElapsed = 0; // = time() - lastTime;
	//lastTime = time();

	//now determine forces on particles
	struct Pointf vNew;
	float angle;
	for(pNum = 0; pNum < numParticles; pNum++) {
		p = &particles[pNum];
		if (p->isActive) {
			if (p->pos.x < 0 || p->pos.x >= envX || p->pos.y < 0 || p->pos.y >= envY) {
				p->isActive = 0;
			} else {
				angle = 3*M_PI/4;
				vNew.x = 0;
				vNew.y = 0;
				for(mx = (int)(p->pos.x)-1; mx <= (int)(p->pos.x)+1; mx++) {
					for(my = (int)(p->pos.y)-1; my <= (int)(p->pos.y)+1; my++) {
						//sum up forces

						//THIS IS CAUSING PROBLEMS, WHY? SINF/COSF ARE NOT DEFINED?!?!
						//vNew.x += env[mx][my]*cosf(angle);
						//vNew.y += env[mx][my]*sinf(angle);
						angle += M_PI/4;
					}
				}
			//TODO: translate vNew to velocity vector
			//find Δ between each of surrounding 8
			//is it worth subrtacting the offset created by the particle itself?
			particles[pNum].velocity.x += vNew.x;
			particles[pNum].velocity.y += vNew.y;
			particles[pNum].pos.x += particles[pNum].velocity.x*timeElapsed;
			particles[pNum].pos.y += particles[pNum].velocity.y*timeElapsed;
			}
		}
	}

	return 0;
} //end of main()

//Update display. Or do this in parallel?
// have a var that keeps track of the last integrated particle and have env map update and display particle in 2 separate threads. A pointer to the map location will be updated.
