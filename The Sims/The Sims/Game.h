#ifndef __GAME_H
#define __GAME_H

#include "Sim.h"
#include <iostream>

class Game
{
	Sim** simsList;
	int MaxSims;
	int	NumOfSims;
public:
	// constructor
	Game(int MaxSims);
	Game(const Game& game);
	~Game();
	// setters 
	void setNumOfSims(int NumOfSims);
	void setMaxSims(int MaxSims);
	// getters
	Sim** getSimsList();
	int getMaxSims();
	int getNumOfSims();
	// methods
	void addSim(Sim* sim);
	void passTime();
	void printSims();
	Sim* findSim(const char* name);
};


#endif