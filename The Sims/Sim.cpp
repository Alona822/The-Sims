#define _CRT_SECURE_NO_WARNINGS
#include "Sim.h"
#include <iostream>
#include <cstring>
using namespace std;

              // constructors //

// default 
Sim::Sim() :Sim("Jane Doe"){}
// name input 
Sim::Sim(const char* name)
{
	setName(name);
	setAge(0);
	setHunger(50);
	setEnergy(50);
}
// all inputs
Sim::Sim(const char* name, int Age, int Hunger, int Energy)
{
	setName(name);
	setAge(Age);
	setHunger(Hunger);
	setEnergy(Energy);
}
// copy
Sim::Sim(const Sim& sim)
{
	setName(sim.name);
	Age = sim.Age;
	Hunger = sim.Hunger;
	Energy = sim.Energy;
}
// destructor
Sim::~Sim()
{
	delete[]name;
	name = NULL;
}
                    // Setters //
void Sim::setName(const char* name)
{
	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Sim::setAge(int Age)
{
	if (Age < 0)
		cout << "Age have to be above 0. value is unchanged." << endl;
	else
		this->Age = Age;
}
void Sim::setHunger(int Hunger)
{
	if (Hunger < 0 || Hunger >100)
		cout << "Hunger have to be between 0-100. value is unchanged." << endl;
	else
		this->Hunger = Hunger;
}
void Sim::setEnergy(int Energy)
{
	if (Energy < 0 || Energy >100)
		cout << "Energy have to be between 0-100. value is unchanged." << endl;
	else
		this->Energy = Energy;
}

                       // Getters //
char* Sim::getName()
{
	return name;
}
int Sim::getAge()
{
	return Age;
}
int Sim::getHunger()
{
	return Hunger;
}
int Sim::getEnergy()
{
	return Energy;
}
                      //	Methods //
void Sim::AgeUp()
{
	setAge(getAge() + 1);
}
void Sim::eat()
{
	setHunger(getHunger() + 15);
}
void Sim::sleep()
{
	setEnergy(getEnergy() + 15);
}

                      //   Print  //
void Sim::print()
{
	//cout << "Sim details:\n";
	cout << "Name: " << name << ", Age: " << getAge() << ",Hunger:" << getHunger() << ", Energy :" << getEnergy() << endl;
}

