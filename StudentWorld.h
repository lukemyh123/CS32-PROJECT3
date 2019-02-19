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

	bool check_collision(double next_x, double next_y);
	void Player_overlapWithExit(double exit_x, double exit_y);
	bool moveToNextLevel() { return go_next_level; }
	bool Player_dead() { return penelope_dead; }
	bool citizen_overlapWithExit(double exit_x, double exit_y);
	bool Player_overlapWithVaccine(double vaccine_x, double vaccine_y);
	void overlapWithPit(double pit_x, double pit_y);

	void setGame_info();


	std::string check_actorsPos(int x, int y);
private:
	std::vector<Actor*> m_actors;
	Penelope* m_penelope;
	bool go_next_level = false;
	bool penelope_dead = false;
};

#endif // STUDENTWORLD_H_
