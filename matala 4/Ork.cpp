#include "Ork.h"
/**
* Ork.cpp
* this is the Ork class, func & desc
* Ork Is A Monstor
* author Ben Mishali
* 26 september 2016
*/

ostream& operator<<(ostream & out, const Ork& A)//operator for print
{
	out << "Ork: "<< A.name << ", points: " << A.points << ", weapon: " << A.arm.getWepName() << ", ammo: " << A.arm.getWepAmmo() << endl;
	return out;
}
void Ork::eat()//eat this ork func
{
	points += 10;
	if (age < 100)//if he is old - more 10 points
		points += 10;
	cout << "Yummy!!! " << name << " thanks master " << master << ". I have now " << points << " points." << endl;
}