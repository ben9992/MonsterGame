#define _CRT_SECURE_NO_WARNINGS
#ifndef _GREMLIN
#define _GREMLIN
#include <iostream>
#include "Monster.h"
using namespace std;
class Gremlin :public Monster
{
protected:
	bool isGood;
public:
	Gremlin(string name1, string wepName,bool goodOrNot) : Monster(name1,wepName,100),isGood(goodOrNot) {};
	friend ostream& operator<<(ostream & out, const Gremlin& A);
	virtual void eat() ;
	virtual void fight() { Monster::fight(); };
	virtual void print()const { cout << *this; };

};
#endif 