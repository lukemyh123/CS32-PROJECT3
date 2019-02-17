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
: GameWorld(assetPath){}

StudentWorld::~StudentWorld()
{
	cleanUp();
}

int StudentWorld::init()
{
	//advanceToNextLevel();
	//int level = getLevel();

	for (int x = 0; x < SPRITE_WIDTH; x++)
	{
		for (int y = 0; y < SPRITE_HEIGHT; y++)
		{
			string name_actor = check_actorsPos(x, y);
			if(name_actor == "wall")
				m_actors.push_back(new Wall(SPRITE_WIDTH * x, SPRITE_HEIGHT * y, this));
			else if(name_actor == "player")
				m_penelope = new Penelope(SPRITE_WIDTH * x, SPRITE_HEIGHT * y, this);
		}	
	}

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //decLives();
	m_penelope->doSomething();
	vector<Actor*>::iterator it;
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
	delete m_penelope;  //delete player
	vector<Actor*>::iterator it;  //delete all actors
	for (it = m_actors.begin(); it != m_actors.end();)
	{
		delete *it;
		it = m_actors.erase(it);
		it++;
	}
}


std::string StudentWorld::check_actorsPos(int x, int y)
{
	Level lev(assetPath());
	string levelFile = "level01.txt";  //getLevel()
	Level::LoadResult result = lev.loadLevel(levelFile);
	if (result == Level::load_fail_file_not_found)
		cerr << "Cannot find level01.txt data file" << endl;
	else if (result == Level::load_fail_bad_format)
		cerr << "Your level was improperly formatted" << endl;
	else if (result == Level::load_success)
	{
		//cerr << "Successfully loaded level" << endl;
		Level::MazeEntry ge = lev.getContentsOf(x, y); // level_x=5, level_y=10
		switch (ge) // so x=80 and y=160
		{
		case Level::empty:
			return "empty";
			break;
		case Level::smart_zombie:
			return "smart_zombie";
			break;
		case Level::dumb_zombie:
			return "dumb_zombie";
			break;
		case Level::player:
			return "player";
			break;
		case Level::exit:
			return "exit";
			break;
		case Level::wall:
			return "wall";
			break;
		case Level::pit:
			return "pit";
			break;
		}
	}
}