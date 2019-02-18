#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class StudentWorld;

class Actor : public GraphObject
{
public:
	Actor(int imageID, double startX, double startY, Direction dir, int depth, StudentWorld *this_world);
	virtual void doSomething() = 0;
	bool isDead() { return object_dead; }
	virtual void setDead() { object_dead = true; }
	StudentWorld * getWorld() { return s_world; }
	virtual bool isBlockActor() = 0;
	~Actor();
private:
	bool object_dead = false;
	StudentWorld* s_world;
};

class Penelope : public Actor
{
public:
	Penelope(double startX, double startY, StudentWorld *this_world);
	virtual void doSomething();
	virtual bool isBlockActor() { return true; }
private:
};

class Wall : public Actor
{
public:
	Wall(double startX, double startYh, StudentWorld *this_world);
	virtual void doSomething() {}
	virtual bool isBlockActor() { return true; }
private:
};


#endif // ACTOR_H_
