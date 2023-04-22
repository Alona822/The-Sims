#pragma once

#ifndef __SIM_H
#define __SIM_H
class Sim
{
private:
	char* name;
	int Age;
	int Hunger;
	int	Energy;
public:
	// constructor
	Sim(); // default
	Sim(const char* name); // input name other default
	Sim(const char* name, int Age, int Hunger, int Energy); // input all
	Sim(const Sim& sim); // copy
	~Sim(); // destructor
	// setters
	void setName(const char* name);
	void setAge(int Age);
	void setHunger(int Hunger);
	void setEnergy(int Energy);
	// getters
	char* getName();
	int getAge();
	int getHunger();
	int getEnergy();
	// methods
	void AgeUp();
	void eat();
	void sleep();
	void print();
};

#endif
