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
	getWorld()->check_collision();
	bool temp_collision_right = getWorld()->if_collision_onRight();
	bool temp_collision_left = getWorld()->if_collision_onLeft();
	bool temp_collision_up = getWorld()->if_collision_onUp();
	bool temp_collision_down = getWorld()->if_collision_onDown();

	//std::cout << temp_collision_up << std::endl;

	if (getWorld()->getKey(ch))
	{
		switch (ch)
		{
		case KEY_PRESS_LEFT:
			if (getDirection() != left)
				setDirection(left);
			else if(!temp_collision_left)
				moveTo(getX() - 4, getY());
			break;
		case KEY_PRESS_RIGHT:
			if (getDirection() != right)
				setDirection(right);
			else if (!temp_collision_right)
				moveTo(getX() + 4, getY());
			break;
		case KEY_PRESS_UP:
			if (getDirection() != up)
				setDirection(up);
			else if (!temp_collision_up)
				moveTo(getX(), getY() + 4);
			break;
		case KEY_PRESS_DOWN:
			if (getDirection() != down)
				setDirection(down);
			else if (!temp_collision_down)
				moveTo(getX(), getY() - 4);
			break;
		}
	}
}

Wall::Wall(double startX, double startY, StudentWorld *this_world)
		: Actor(IID_WALL, startX, startY, right, 0, this_world){}
