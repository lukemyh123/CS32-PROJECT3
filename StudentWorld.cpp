#include "StudentWorld.h"
#include "GameConstants.h"

#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
}

int StudentWorld::init()
{
	m_actors.push_back(new Wall(55, 100, this));
	m_actors.push_back(new Wall(100, 200, this));

	//m_penelope = new Penelope(SPRITE_WIDTH * level_x, SPRITE_HEIGHT * level_y);
	m_penelope = new Penelope(80, 80, this);

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //decLives();
	m_penelope->doSomething();

    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
	delete m_penelope;
	vector<Actor*>::iterator it;
	for (it = m_actors.begin(); it != m_actors.end();)
	{
		delete *it;
		it = m_actors.erase(it);
		it++;
	}

}
