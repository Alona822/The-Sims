#pragma warning (disable: 4996)

#include "Sim.h"
#include "Game.h"
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	//// first question checking
	//Sim Jane, Dan("Dan"), Alona("Alona", 27, 90, 20);
	//Jane.print(), Dan.print(), Alona.print();
	Game Sims(5);
	cout << "------Welcome to Sims Game------" << endl;
	cout << "In this game allowed only 5 sims" << endl;
	int choise = 0;
	char name[20];
	do
	{
		cout << endl;
		cout << "Choose your action:" << endl;
		cout << "1. Add New Sim" << endl
			<< "2. Action on existing Sim" << endl
			<< "3. Pass time" << endl
			<< "4. Print status" << endl
			<< "5. Exit" << endl
			<< endl;
		
			cin >> choise;
			switch (choise)
			{
			case 1: // add new sim 
			{
				cout << "Enter Sim Name:" << endl;
				cin >> name;
				Sim* newSim = new Sim(name);
				Sims.addSim(newSim);
				break;
			}
			case 2: // perform action on existing sim
			{
				int action;
				cout << "Choose Sim by name:" << endl;
				cin >> name;
				Sim* toFind = Sims.findSim(name);
				if (toFind == nullptr) break;
				cout << "Choose action:" << endl;
				cout << "1.eat" << endl
					<< "2.sleep" << endl
					<< "3.age up" << endl
					<< "4.go back to previous menu" << endl
					<< endl;
				cin >> action;
				switch (action)
				{
				case 1: // eat
					toFind->eat();
					cout << toFind->getName() << " ate" << endl;
					toFind->print();
					break;
				case 2: // sleep
					toFind->sleep();
					cout << toFind->getName() << " slept" << endl;
					toFind->print();
					break;
				case 3: // to mature sim in a year
					toFind->AgeUp();
					cout << toFind->getName() << " aged up by 1 year" << endl;
					toFind->print();
					break;
				case 4: // return to main
					break;
				default:
					cout << "Invalid choice Please enter a number from 1 to 4." << endl;
					break;
				} break;
			}
			case 3: // Pass time
				Sims.passTime();
				break;
			case 4: // print status 
				Sims.printSims();
				break;
			case 5: // Exit
				cout << "Bye-Bye" << endl;
				return 0;
			default:
				cout << "Invalid choice Please enter a number from 1 to 5." << endl;
				break;
			}
	} while (choise != 5);
}
