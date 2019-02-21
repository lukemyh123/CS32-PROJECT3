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
    virtual bool canBeDamagedByFlame() = 0;
    virtual bool isAFlame() { return false;}
    virtual bool person() { return false; }
    virtual void setActive() { active = true; }
    virtual void setNotActive() { active = false; }
    virtual bool getActive() { return active; }
    ~Actor();
private:
    bool object_alive = true;
    StudentWorld* s_world;
    bool active = false;  //for landmine
};

class Penelope : public Actor
{
public:
    Penelope(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return true; }
    virtual bool canBeDamagedByFlame() { return true; }
    virtual bool person() { return true; }
private:
};

class Wall : public Actor
{
public:
    Wall(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething() {}
    virtual bool isBlockActor() { return true; }
    virtual bool canBeDamagedByFlame() { return false; }
private:
};

class Exit : public Actor  // 3 for Exit
{
public:
    Exit(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
};

class Pit : public Actor
{
public:
    Pit(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
    
};

class Flame : public Actor
{
public:
    Flame(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
    virtual bool isAFlame() { return true; }
    
private:
    int tick = 0;
};


class Vaccine_goodie : public Actor
{
public:
    Vaccine_goodie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return true; }
    
private:
};

class Gas_can_goodie : public Actor
{
public:
    Gas_can_goodie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return true; }
};

class Landmine_goodie : public Actor
{
public:
    Landmine_goodie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return true; }
};

class Landmine : public Actor
{
public:
    Landmine(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return true; }
    
private:
    int tick = 30;
};


#endif // ACTOR_H_
