#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include "Actor.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
	~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();

	void check_collision(int next_x, int next_y);


	void set_left(bool a) { box_onLeft = a; }
	void set_right(bool a) { box_onRight = a; }
	void set_up(bool a) { box_onUp = a; }
	void set_down(bool a) { box_onDown = a; }

	bool if_collision_onLeft() { return box_onLeft; }
	bool if_collision_onRight() { return box_onRight; }
	bool if_collision_onUp() { return box_onUp; }
	bool if_collision_onDown() { return box_onDown; }

	std::string check_actorsPos(int x, int y);
private:
	std::vector<Actor*> m_actors;
	Penelope* m_penelope;
	bool box_onLeft;
	bool box_onRight;
	bool box_onUp;
	bool box_onDown;

};

#endif // STUDENTWORLD_H_
