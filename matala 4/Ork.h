#define _CRT_SECURE_NO_WARNINGS
#ifndef _ORK
#define _ORK
#include <iostream>
#include "Monster.h"
using namespace std;
class Ork :public Monster
{
protected:
	int age;
public:
	Ork(string name1, string wepName, int age1) : Monster(name1, wepName, 100) { if (age1 < 0) age = 0; else age = age1; };
	friend ostream& operator<<(ostream & out, const Ork& A);
	virtual void eat();
	virtual void fight() { Monster::fight(); }
	virtual void print()const { cout << *this; }
};
#endif