#include "StudentWorld.h"
#include "GameConstants.h"
#include <sstream>   //ostringstream
#include <string>
#include <iomanip>  //setw()
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
	//cleanUp();
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
			if (name_actor == "wall")
				m_actors.push_back(new Wall(SPRITE_WIDTH * x, SPRITE_HEIGHT * y, this));
			else if (name_actor == "player")
				m_penelope = new Penelope(SPRITE_WIDTH * x, SPRITE_HEIGHT * y, this);
			else if (name_actor == "exit")
				m_actors.push_back(new Exit(SPRITE_WIDTH * x, SPRITE_HEIGHT * y, this));
		}	
	}

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //decLives();
	setGame_info();
	m_penelope->doSomething();
	vector<Actor*>::iterator it;  //delete all actors
	for (it = m_actors.begin(); it != m_actors.end(); it++)
	{
		(*it)->doSomething();
	}

	if (getLevel() == 2)
		return GWSTATUS_FINISHED_LEVEL;
	
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
	//if(m_penelope != nullptr)
		delete m_penelope;  //delete player
	vector<Actor*>::iterator it;  //delete all actors
	//if (m_actors.size() != 0)
	//{
		for (it = m_actors.begin(); it != m_actors.end();)
		{
			delete *it;
			it = m_actors.erase(it);
			it++;
		}
	//}
}

bool StudentWorld::check_collision(double next_x, double next_y)
{
	vector<Actor*>::iterator it;
	for (it = m_actors.begin(); it != m_actors.end();it++)
	{		
		if ((*it)->isBlockActor() == true)  //check whether the actors are bounder boxs collision 
		{    
			if ((next_x + SPRITE_WIDTH-1) >= ((*it)->getX())
				&& (next_x) <= ((*it)->getX() + SPRITE_WIDTH-1)
				&& (next_y + SPRITE_HEIGHT-1) >= ((*it)->getY())
				&& (next_y) <= ((*it)->getY() + SPRITE_HEIGHT-1))
			{
				return true;
			}
		}
	}
	return false;
}

bool StudentWorld::overlapWithExit(double exit_x, double exit_y)    //check if any actors are overlap with Exit
{
	vector<Actor*>::iterator it;
	double player_x = m_penelope->getX();
	double player_y = m_penelope->getY(); 
	
	if (pow(player_x - exit_x, 2) + pow(player_y - exit_y, 2) <= 100)  //overlap(x1-x2)^2 + (y1-y2)^2 ≤ 10^2
		return true;

	return false;
}

void StudentWorld::setGame_info()
{
	ostringstream print_info;
	print_info.setf(ios::fixed);

	//Score:	004500		Level:	27		Lives:	3		Vaccines:	2		Flames:	16		Mines:	1		Infected:	0
	print_info <<"Score: " << setw(2) << getScore()<< "  Level: " <<setw(2) << getLevel() << "  Lives: " << setw(2) << getLives()
		<< "  Vaccines: " << setw(2) << 0 << "  Flames; " << setw(2) << 0 <<"  Mines: " << setw(2) << 0 << "  Infected: " << setw(2) << 0;
	setGameStatText(print_info.str());
}

std::string StudentWorld::check_actorsPos(int x, int y)
{
	Level lev(assetPath());
	string levelFile;
	if(getLevel() == 1)
		levelFile = "level01.txt";  //getLevel()
	if(getLevel() == 2)
		levelFile = "level02.txt";  //getLevel()

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