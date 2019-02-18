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
