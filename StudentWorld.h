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
	~StudentWorld(){}
    virtual int init();
    virtual int move();
    virtual void cleanUp();

private:
	std::vector<Actor*> m_actors;
	Penelope* m_penelope;
};

#endif // STUDENTWORLD_H_
