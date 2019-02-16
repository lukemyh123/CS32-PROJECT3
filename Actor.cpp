#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
Actor::Actor(int imageID, double startX, double startY, Direction dir, int depth, StudentWorld *this_world)
	:GraphObject(imageID, startX, startY, dir, depth), s_world(this_world)
{}

Actor::~Actor(){}

Penelope::Penelope(double startX, double startY, StudentWorld *this_world)
	:Actor(IID_PLAYER, startX, startY, right, 0, this_world)
{}

void Penelope::doSomething()
{
	int ch;
	if (getWorld()->getKey(ch))
	{
		switch (ch)
		{
		case KEY_PRESS_LEFT:
			if (getDirection() != left)
				setDirection(left);
			else
				moveTo(getX() - 1, getY());
			break;
		case KEY_PRESS_RIGHT:
			if (getDirection() != right)
				setDirection(right);
			else
				moveTo(getX() + 1, getY());
			break;
		case KEY_PRESS_UP:
			if (getDirection() != up)
				setDirection(up);
			else
				moveTo(getX(), getY() + 1);
			break;
		case KEY_PRESS_DOWN:
			if (getDirection() != down)
				setDirection(down);
			else
				moveTo(getX(), getY() - 1);
			break;
		}
	}
}


Wall::Wall(double startX, double startY, StudentWorld *this_world)
		: Actor(IID_WALL, startX, startY, right, 0, this_world)
{}
