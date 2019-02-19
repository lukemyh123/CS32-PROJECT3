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
	bool getStatus() { return object_alive; }
	virtual void setDead() { object_alive = false; }
	virtual void setAlive() { object_alive = true; }
	StudentWorld * getWorld() { return s_world; }
	virtual bool isBlockActor() = 0;
	~Actor();
private:
	bool object_alive = true;
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
	Wall(double startX, double startY, StudentWorld *this_world);
	virtual void doSomething() {}
	virtual bool isBlockActor() { return true; }
private:
};

class Exit : public Actor
{
public:
	Exit(double startX, double startY, StudentWorld *this_world);
	virtual void doSomething();
	virtual bool isBlockActor() { return false; }
};

class Pit : public Actor
{
public:
	Pit(double startX, double startY, StudentWorld *this_world);
	virtual void doSomething();
	virtual bool isBlockActor() { return false; }
};

class Flame : public Actor
{
public:
	Flame(double startX, double startY, StudentWorld *this_world);
	virtual void doSomething();
	virtual bool isBlockActor() { return false; }
};

class Goodie : public Actor
{
public:
	Goodie(int image_ID, double startX, double startY, StudentWorld *this_world);
	virtual void doSomething();
	virtual bool isBlockActor() { return false; }
};

class Vaccine_goodie : public Goodie
{
public:
	Vaccine_goodie(double startX, double startY, StudentWorld *this_world);
};

class Gas_can_goodie : public Goodie
{
public:
	Gas_can_goodie(double startX, double startY, StudentWorld *this_world);
};

class Landmine_goodie : public Goodie
{
public:
	Landmine_goodie(double startX, double startYh, StudentWorld *this_world);

};

#endif // ACTOR_H_
