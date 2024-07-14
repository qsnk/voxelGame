#include "world.hpp"
#include "../includes.hpp"

float planeVertices[] = {
	-5.0f, 0.0f,  5.0f,
	 5.0f, 0.0f,  5.0f,
	 5.0f, 0.0f, -5.0f,
	-5.0f, 0.0f, -5.0f
};

uint planeIndices[] = {
  	0, 1, 2,
    2, 3, 0
};


void World::createPlane() {}