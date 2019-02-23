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
	bool block_flame(double x, double y);
	void Player_overlapWithExit(double exit_x, double exit_y);
	bool moveToNextLevel() { return go_next_level; }
	bool citizen_overlapWithExit(double exit_x, double exit_y);

	bool Player_overlapWith_Goodies(double goodies_x, double goodies_y);

	void overlapWithPit(double pit_x, double pit_y);
	void overlapWithFlame(double flame_x, double flame_y);

	void fire(double x, double y, int dir);

	void placeLandmine(double x, double y);
	void landmineBoom(double landmine_x, double landmine_y);
	bool overlapwithLandmine(double x, double y);

	void reset_goodies() { vaccine = 0; flamethrower = 0; landmines = 0; }
	void add_vaccine() { vaccine++; }
	void reduce_vaccine() { vaccine--; }
	void add_flamethrower() { flamethrower += 5; }
	void reduce_flamethrower() { flamethrower--; }
	void add_landmines() { landmines += 2; }
	void reduce_landmines() { landmines--; }
	int get_vaccine() { return vaccine; }
	int get_flamethrower() { return flamethrower; }
	int get_landmines() { return landmines; }

	void setGame_info();


	std::string check_actorsPos(int x, int y);
private:
	std::vector<Actor*> m_actors;
	Penelope* m_penelope;
	bool go_next_level = false;
	int vaccine = 0;
	int flamethrower = 0;
	int landmines = 0;
};

#endif // STUDENTWORLD_H_