#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
Actor::Actor(int imageID, double startX, double startY, Direction dir, int depth)
	:GraphObject(imageID, startX, startY, dir, depth)
{}

Actor::~Actor(){}

Penelope::Penelope(int imageID, double startX, double startY, Direction dir, int depth)
	:Actor(imageID, startX, startY, dir, depth)
{}

Penelope::~Penelope(){}