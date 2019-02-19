#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
Actor::Actor(int imageID, double startX, double startY, Direction dir, int depth, StudentWorld *this_world)
	:GraphObject(imageID, startX, startY, dir, depth), s_world(this_world)
{}

Actor::~Actor(){}

Penelope::Penelope(double startX, double startY, StudentWorld *this_world)
	:Actor(IID_PLAYER, startX, startY, right, 0, this_world){}

void Penelope::doSomething()
{
	int ch;
	//std::cout << temp_collision_up << std::endl;

	if (getWorld()->getKey(ch))
	{
		switch (ch)
		{
		case KEY_PRESS_LEFT:
			if (getDirection() != left)
				setDirection(left);
			else if(!getWorld()->check_collision(getX() - 4, getY())) //check if the next left has blocking
				moveTo(getX() - 4, getY());
			break;
		case KEY_PRESS_RIGHT:
			if (getDirection() != right)
				setDirection(right);
			else if(!getWorld()->check_collision(getX() + 4, getY())) //check if the next right has blocking
				moveTo(getX() + 4, getY());
			break;
		case KEY_PRESS_UP:
			if (getDirection() != up)
				setDirection(up);
			else if(!getWorld()->check_collision(getX(), getY() + 4))  //check if the next up has blocking
				moveTo(getX(), getY() + 4);		
			break;
		case KEY_PRESS_DOWN:
			if (getDirection() != down)
				setDirection(down);
			else if(!getWorld()->check_collision(getX(), getY() - 4))  //check if the down has blocking
				moveTo(getX(), getY() - 4);
			break;
		}
	}
}

Wall::Wall(double startX, double startY, StudentWorld *this_world)
		: Actor(IID_WALL, startX, startY, right, 0, this_world){}

Exit::Exit(double startX, double startY, StudentWorld *this_world)
	: Actor(IID_EXIT, startX, startY, right, 1, this_world){}

void Exit::doSomething()
{
	bool temp = getWorld()->Player_overlapWithExit(getX(), getY());   //If the player is overlap with Exit and no more citizen, goes to next level

	if (getWorld()->citizen_overlapWithExit(getX(), getY()) == true)  //If the citizen are overlap with Eixt, destory them ,and add score
		std::cout << "Delete citizen" << std::endl;

}

Pit::Pit(double startX, double startY, StudentWorld *this_world)
	: Actor(IID_PIT, startX, startY, right, 0, this_world) {}

void Pit::doSomething()
{
	if (getWorld()->overlapWithPit(getX(), getY()) == true)       //if the plaer is overlap with Pit, decLives();
		getWorld()->decLives();
}