#include "Manager.h"
#include "Gremlin.h"
#include "Ork.h"

/**
* Manger.cpp
* this is the Manger class, func & desc
* plays the main game, the menu and more
* author Ben Mishali
* 26 september 2016
*/

Manager::~Manager()//dtor
{
	for (int i = 0; i < V.size(); i++)
		delete V[i];
}

void Manager::start()
{
	string masterName;
	int i = 0;
	int choice = 0;
	cout << "Welcome to the Monsters World master." << endl;
	cout << "What is your name master?";
	cin >> masterName;
	Monster::setMaster(masterName);

	while (i != EXIT)
	{
		displayMenu();
		cout << "What would you like to do master " << masterName << "?" << endl;
		cin >> i;
		switch (i)// switch case for the menu
		{
		case SHOW_MENU:
		{
			displayMenu();
		}
		break;
		case CREATE_GREMLIN:
		{
			try { create(CREATE_GREMLIN); }
			catch (const char* A)
			{
				cout << A << endl;
				break;
			}
		}
		break;
		case CREATE_ORK:
		{

			try { create(CREATE_ORK); }
			catch (const char* A)
			{
				cout << A << endl;
				break;
			}
		}
			break;
		case FEED:
		{
			monsterAv();
			cout << "Which monster do you want to feed ?" << endl;
			cin >> choice;
			while ((checkChoice(choice) == false))
				cin >> choice;
			V[choice]->eat();
		}
		break;
		case FIGHT:
		{
			monsterAv();
			cout << "Which monster do you want to fight ?" << endl;
			cin >> choice;
			while ((checkChoice(choice) == false))
				cin >> choice;
			try { V[choice]->fight(); }
			catch (const char* A)
			{
				cout << A << endl;
				break;
			}
		}
			break;
		case LOAD:
		{
			monsterAv();
			cout << "Which monster do you want to relode ?" << endl;
			cin >> choice;
			while ((checkChoice(choice) == false))
				cin >> choice;
			try { V[choice]->relode(); }
			catch (const char* A)
			{
				cout << A << endl;
				break;
			}

			break;

		}
		break;
		case SHOW_ALL:
		{
			cout << "Gremlins:" << endl;
			for (int i = 0; i < V.size(); i++)
				if (dynamic_cast <const Gremlin*> (V[i]) != NULL)
					V[i]->print();
			cout << "Orks:" << endl;
			for (int i = 0; i < V.size(); i++)
				if (dynamic_cast <const Ork*> (V[i]) != NULL)
					V[i]->print();
		}
		break;
		case EXIT:
		{
			cout << "GoodBye master " << masterName << "! It was fun playing with you!" << endl;
			exit(0);// delete vector and esc.
		}
		default:
			cout << "Choose again: " << endl;
			break;
		}
	}
}

	void Manager::displayMenu()const
	{
		cout << "[0] - Display the menu again." << endl;
		cout << "[1] - Create a Gremlin." << endl;
		cout << "[2] - Create an Ork." << endl;
		cout << "[3] - Feed." << endl;
		cout << "[4] - Fight." << endl;
		cout << "[5] - Load ammo." << endl;
		cout << "[6] - Print all details." << endl;
		cout << "[7] - Exit." << endl;
	}

	void Manager::create(int type) //create a monstor
	{
		string name;
		string wepName;
		cout << "Please enter monster name: " << endl;
		cin >> name;
		cout << "Please enter monster weapon: " << endl;
		cin >> wepName;
		if (type == 1)
		{
			int goodOrNot;
			cout << "Please enter if he's Good or Not(true=1/false=0): " << endl;
			cin >> goodOrNot;
			if (goodOrNot != 1 && goodOrNot != 0)
				throw "Wrong selection, your monster wont live.";
			Gremlin* A = new Gremlin(name, wepName, goodOrNot);
				V.insert(V.begin(), A);
				cout << "Gremlin " << name << " was born successfully!" << endl;
		}
		else
		{
			int age1;
			cout << "Please enter monster age: " << endl;
			cin >> age1;
			Ork* A=new Ork(name, wepName,age1 );
				V.insert(V.begin(), A);
				cout << "Ork " << name << " was born successfully!" << endl;
		}
	}

	void Manager::monsterAv() const // available of monstor
	{
		cout << "The available monsters are :" << endl;
		for (int i = 0; i < V.size(); i++)
		{
			cout << "[" << i << "]" << " - "; V[i]->print(); cout << endl;
		}
	}

	bool Manager::checkChoice(int c) const //user choice
	{
		if (c<0 || c>=V.size()) {
			cout << "Wrong selection, Choose again :" << endl;
			return false;
		}
		else return true;
	}
