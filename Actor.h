#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor : public GraphObject
{
public:
	Actor(int imageID, double startX, double startY, Direction dir, int depth);
	~Actor();
private:
};

class Penelope : public Actor
{
public:
	Penelope(int imageID, double startX, double startY, Direction dir, int depth);
	~Penelope();
private:
};

class Wall :public Actor
{
public:
private:
};


#endif // ACTOR_H_
