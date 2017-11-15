#include "Gremlin.h"

/**
* Gremlin.cpp
* this is the Gremlin class, func & desc
* Gremlin Is A Monstor
* author Ben Mishali
* 26 september 2016
*/
ostream& operator<<(ostream & out, const Gremlin& A) // operator for print
{
	out << "Gremlin: ";
	if (A.isGood == 1)
		cout << "Good ";
	else
		cout << "Bad ";
		cout<< A.name << ", points: " << A.points << ", weapon: " << A.arm.getWepName()<<", ammo: "<<A.arm.getWepAmmo()<<endl;
	return out;
}

void Gremlin::eat() // how the gremlin eats
{
	this->points += 10; 
	cout << "Yummy!!! " << name << " thanks master " << master << ". I have now " << points << " points." << endl;
}


