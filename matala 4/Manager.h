#ifndef _MANAGER
#define _MANAGER
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
enum Options
{
	SHOW_MENU, CREATE_GREMLIN, CREATE_ORK, FEED, FIGHT,LOAD,SHOW_ALL, EXIT
};
using namespace std;
class Manager  {
protected:
	vector<Monster*> V;
public:
	Manager() {};
	~Manager();
	void start();
	void displayMenu()const;//printing func
	void create(int type);
	void monsterAv()const;//printing func
	bool checkChoice(int c)const;// checking func
};
#endif
