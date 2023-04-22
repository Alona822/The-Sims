#include "Game.h"
#include <iostream>
#include <ctime>
using namespace std;

					// constructors //
Game::Game(int MaxSims)
{
	this->NumOfSims = 0;
	this->MaxSims = MaxSims;
	simsList = new Sim * [MaxSims];
}
Game::Game(const Game& game)
{
	simsList = game.simsList;
	MaxSims = game.MaxSims;
	NumOfSims = game.NumOfSims;
}
Game::~Game()
{
	int i;
	for (i = 0; i < NumOfSims; i++) {
		delete simsList[i];
	}
	delete[] simsList;
}

					// Setters //
void Game::setNumOfSims(int NumOfSims)
{
	this->NumOfSims = NumOfSims;
}
void Game::setMaxSims(int MaxSims)
{
	this->MaxSims = MaxSims;
}

					// Getters //
Sim** Game::getSimsList()
{
	return simsList;
}
int Game::getMaxSims()
{
	return MaxSims;
}
int Game::getNumOfSims()
{
	return NumOfSims;
}


                     // methods //

void Game::addSim(Sim* sim)
{
	if (NumOfSims < MaxSims) {

		simsList[NumOfSims] = sim;
		NumOfSims++;
		this->printSims();
	}
	else { cout << "not enough space" << endl; }
}
void Game::passTime()
{
	srand(time(0));
	for (int i = 0; i < NumOfSims; i++)
	{
		simsList[i]->AgeUp();
		simsList[i]->setEnergy(simsList[i]->getEnergy() - (rand() % 15 + 1));
		simsList[i]->setHunger(simsList[i]->getHunger() - (rand() % 15 + 1));
	}
	cout << "Time passes...." << endl;
	printSims();
}
void Game::printSims()
{
	cout << "Sims details:" << endl;
	for (int i = 0; i < NumOfSims; i++)
	{
		simsList[i] -> print();
	}
}
Sim* Game::findSim(const char* name)
{
	for (int i = 0; i < NumOfSims; i++) {
		if (!(strcmp(simsList[i]->getName(), name)))
		{
			return simsList[i];
		}
	}
	cout << "The Sim is not exist" << endl;
	return nullptr;
}