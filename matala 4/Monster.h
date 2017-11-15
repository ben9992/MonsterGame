#define _CRT_SECURE_NO_WARNINGS
#ifndef _MONSTER
#define _MONSTER
#include <iostream>
#include <string>
#include "Weapon.h"
using namespace std;
class Monster
{
protected:
	static string master;
	string name;
	int points;
	Weapon arm;
public:
	Monster(string name1="noname",string wepName = "noname", int points1 = 100) : name(name1),points(points1),arm(wepName) {};
	virtual void eat() = 0;
	virtual void fight();
	virtual void print()const = 0;
	virtual void relode();
	void static setMaster(string mas) { master = mas; }// static func to set master
	bool checkPoints(int p) const;// checking func
	


};

#endif 
