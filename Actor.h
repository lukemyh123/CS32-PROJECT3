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
    virtual bool canBeDamagedByVomit() { return false; }
    virtual bool canBlockFlameandVomit() { return false; }
    virtual bool isAFlame() { return false; }
    virtual bool person() { return false; }
    
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
    virtual bool canBeDamagedByFlame() { return true; }
    virtual bool canBeDamagedByVomit() { return true; }
    virtual bool getInfection_status() { return infection_status; }
    virtual void setInfection() { infection_status = true; }
    virtual void cureInfection() { infection_status = false; }
    int getInfectedNumber() { return infection; }
    virtual bool person() { return true; }
private:
    int infection;
    bool infection_status;
};

class Wall : public Actor
{
public:
    Wall(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething() {}
    virtual bool isBlockActor() { return true; }
    virtual bool canBeDamagedByFlame() { return false; }
    virtual bool canBlockFlameandVomit() { return true; }
    
private:
};

class Exit : public Actor  // 3 for Exit
{
public:
    Exit(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
    virtual bool canBlockFlameandVomit() { return true; }
    
};

class Pit : public Actor
{
public:
    Pit(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
};

class Projectile:public Actor
{
public:
    Projectile(int imageID, double startX, double startY, StudentWorld *this_world);
    virtual bool doSomethingCom();
    virtual void doSomething() = 0;
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
    virtual bool isAFlame() = 0;
    
private:
    int tick = 0;
};
class Flame : public Projectile
{
public:
    Flame(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
    virtual bool isAFlame() { return true; }
};

class Vomit : public Projectile
{
public:
    Vomit(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return false; }
    virtual bool isAFlame() { return false; }
};

class Googie : public Actor
{
public:
    Googie(int imageID, double startX, double startY, StudentWorld *this_world);
    virtual bool doSomethingCom();
    virtual void doSomething() = 0;
    virtual bool isBlockActor() { return false; }
    virtual bool canBeDamagedByFlame() { return true; }
};

class Vaccine_goodie : public Googie
{
public:
    Vaccine_goodie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
    
private:
};

class Gas_can_goodie : public Googie
{
public:
    Gas_can_goodie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
};

class Landmine_goodie : public Googie
{
public:
    Landmine_goodie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
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

class Zombie : public Actor
{
public:
    Zombie(int imageID, double startX, double startY, StudentWorld *this_world);
    virtual void doSomethingCom();
    virtual void doSomethingVomitCom();
    virtual void doSomething() = 0;
    virtual bool isBlockActor() { return true; }
    virtual bool canBeDamagedByFlame() { return true; }
    virtual bool person() { return true; }
private:
    int tick;
    int movement_plan;
    int rand_dir;
};


class DumbZombie : public Zombie
{
public:
    DumbZombie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
};

class SmartZombie : public Zombie
{
public:
    SmartZombie(double startX, double startY, StudentWorld *this_world);
    virtual void doSomething();
private:
    double cloest_x;
    double cloest_y;
    double distance;
};
#endif // ACTOR_H_
