#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
Actor::Actor(int imageID, double startX, double startY, Direction dir, int depth, StudentWorld *this_world)
:GraphObject(imageID, startX, startY, dir, depth), s_world(this_world)
{}

Actor::~Actor() {}

Penelope::Penelope(double startX, double startY, StudentWorld *this_world)
: Actor(IID_PLAYER, startX, startY, right, 0, this_world)
{
    setAlive();
}

void Penelope::doSomething()
{
    int ch;
    
    if (getStatus() == false)
        return;
    
    if (getWorld()->getKey(ch))
    {
        switch (ch)
        {
            case KEY_PRESS_LEFT:
                if (getDirection() != left)
                {
                    setDirection(left);
                    if (!getWorld()->check_collision(getX() - 4, getY()))
                        moveTo(getX() - 4, getY());
                }
                else if (!getWorld()->check_collision(getX() - 4, getY())) //check if the next left has blocking
                    moveTo(getX() - 4, getY());
                break;
            case KEY_PRESS_RIGHT:
                if (getDirection() != right)
                {
                    setDirection(right);
                    if (!getWorld()->check_collision(getX() + 4, getY()))
                        moveTo(getX() + 4, getY());
                }
                else if (!getWorld()->check_collision(getX() + 4, getY())) //check if the next right has blocking
                    moveTo(getX() + 4, getY());
                break;
            case KEY_PRESS_UP:
                if (getDirection() != up)
                {
                    setDirection(up);
                    if (!getWorld()->check_collision(getX(), getY() + 4))
                        moveTo(getX(), getY() + 4);
                }
                else if (!getWorld()->check_collision(getX(), getY() + 4))  //check if the next up has blocking
                    moveTo(getX(), getY() + 4);
                break;
            case KEY_PRESS_DOWN:
                if (getDirection() != down)
                {
                    setDirection(down);
                    if (!getWorld()->check_collision(getX(), getY() - 4))
                        moveTo(getX(), getY() - 4);
                }
                else if (!getWorld()->check_collision(getX(), getY() - 4))  //check if the down has blocking
                    moveTo(getX(), getY() - 4);
                break;
            case KEY_PRESS_SPACE:
                if (getDirection() == left && getWorld()->get_flamethrower() != 0)
                {
                    getWorld()->fire(getX(), getY(), 1);
                    getWorld()->reduce_flamethrower();
                    //std::cout <<" Fire " << std::endl;  //produce fire;
                }
                else if (getDirection() == right && getWorld()->get_flamethrower() != 0)
                {
                    getWorld()->fire(getX(), getY(), 2);
                    getWorld()->reduce_flamethrower();
                    //std::cout <<" Fire " << std::endl;  //produce fire;
                }
                else if (getDirection() == up && getWorld()->get_flamethrower() != 0)
                {
                    getWorld()->fire(getX(), getY(), 3);
                    getWorld()->reduce_flamethrower();
                    //std::cout <<" Fire " << std::endl;  //produce fire;
                }
                else if (getDirection() == down && getWorld()->get_flamethrower() != 0)
                {
                    getWorld()->fire(getX(), getY(), 4);
                    getWorld()->reduce_flamethrower();
                    //std::cout <<" Fire " << std::endl;  //produce fire;
                }
                break;
            case KEY_PRESS_TAB:
                if (getWorld()->get_landmines() != 0)
                    getWorld()->placeLandmine(getX(), getY());
                break;
        }
    }
}

Wall::Wall(double startX, double startY, StudentWorld *this_world)
: Actor(IID_WALL, startX, startY, right, 0, this_world) {}

Exit::Exit(double startX, double startY, StudentWorld *this_world)
: Actor(IID_EXIT, startX, startY, right, 1, this_world)
{}

void Exit::doSomething()
{
    getWorld()->Player_overlapWithExit(getX(), getY());   //If the player is overlap with Exit and no more citizen, goes to next level
    //getWorld()->check_FlameoverlapWithExit(getX(), getY()); //flame overlap with Exit, block flame
    //std::cout << "exit blocks flame" << std::endl;
    
    if (getWorld()->citizen_overlapWithExit(getX(), getY()) == true)  //If the citizen are overlap with Eixt, destory them ,and add score
        std::cout << "Delete citizen" << std::endl;
    
}

Pit::Pit(double startX, double startY, StudentWorld *this_world)
: Actor(IID_PIT, startX, startY, right, 0, this_world) {}

void Pit::doSomething()
{
    getWorld()->overlapWithPit(getX(), getY());      //if any actors are overlap with Pit, decLives();
}

Flame::Flame(double startX, double startY, StudentWorld *this_world)
: Actor(IID_FLAME, startX, startY, right, 0, this_world)
{
    setAlive();
}
void Flame::doSomething()
{
    if (getStatus() == false)
        return;
    
    tick++;
    
    getWorld()->overlapWithFlame(getX(), getY());
    
    if (tick == 2)
        setDead();
}

Googie::Googie(int imageID, double startX, double startY, StudentWorld *this_world)
: Actor(imageID, startX, startY, right, 1, this_world)
{
    setAlive();
}
bool Googie::doSomethingCom()
{
    if (getStatus() == false)
        return false;
    
    if (getWorld()->Player_overlapWith_VaccineGoodies(getX(), getY()))
    {
        setDead();
        return true;
    }
    return false;
}

Vaccine_goodie::Vaccine_goodie(double startX, double startY, StudentWorld *this_world)
: Googie(IID_VACCINE_GOODIE, startX, startY, this_world) {}
void Vaccine_goodie::doSomething()
{
    if(Googie::doSomethingCom())
        getWorld()->add_vaccine();
}

Gas_can_goodie::Gas_can_goodie(double startX, double startY, StudentWorld *this_world)
: Googie(IID_GAS_CAN_GOODIE, startX, startY, this_world){}
void Gas_can_goodie::doSomething()
{
    if(Googie::doSomethingCom())
    getWorld()->add_flamethrower();
}

Landmine_goodie::Landmine_goodie(double startX, double startY, StudentWorld *this_world)
: Googie(IID_LANDMINE_GOODIE, startX, startY, this_world){}
void Landmine_goodie::doSomething()
{
    if(Googie::doSomethingCom())
    getWorld()->add_landmines();
}

Landmine::Landmine(double startX, double startY, StudentWorld *this_world)
: Actor(IID_LANDMINE, startX, startY, right, 1, this_world)
{
    setAlive();
}
void Landmine::doSomething()
{
    if (getStatus() == false)
        return;
    
    tick--;
    if (tick <= 0)
    {  //landmine becomes active, and check if any person is overlap with landmine
        if (getWorld()->overlapwithLandmine(getX(), getY()))
        {
            getWorld()->landmineBoom(getX(), getY());
            setDead();
        }
    }
    return;
}

DumbZombie::DumbZombie(double startX, double startY, StudentWorld *this_world)
:Actor(IID_ZOMBIE, startX, startY, right, 0, this_world)
{
    setAlive();
    movement_plan = 0;
    tick = 0;
    
}

void DumbZombie::doSomething()
{
    if (getStatus() == false)
        return;
    
    tick++;
    if (movement_plan == 0)
        movement_plan = randInt(3, 10);
    
    if (tick % 2 == 0)
        return;
    
   // std::cout << tick << std::endl;
    if (tick % 2 != 0)
    {
        int rand_dir = randInt(1, 4);  //random direction
        if (rand_dir == 1)
        {
            setDirection(up);
            moveTo(getX(), getY() + 1);
        }
        else if (rand_dir == 2)
        {
            setDirection(down);
            moveTo(getX(), getY() - 1);
        }
        else if (rand_dir == 3)
        {
            setDirection(left);
            moveTo(getX() - 1, getY());
        }
        else if (rand_dir == 4)
        {
            setDirection(right);
            moveTo(getX() + 1, getY());
        }
        
        if (getDirection() == up)
            moveTo(getX(), getY() + 1);
        else if (getDirection() == down)
            moveTo(getX(), getY() - 1);
        else if (getDirection() == left)
            moveTo(getX() - 1, getY());
        else if (getDirection() == right)
            moveTo(getX() + 1, getY());
        
        movement_plan--;
        //need to check the bounding box;
        
    }
}
