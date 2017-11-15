/**
* Monstor.cpp
* this is the monstor class, func & desc
* 
* author Ben Mishali
* 26 september 2016
*/

#include "Monster.h"
string Monster::master = "noname"; // global name

void Monster::fight() // fight func between monstor
{
	if (checkPoints(arm.getWepAmmo() - 10)==false)
		throw "He cannot fight, load your monster weapon.";
	if (checkPoints(points - 10)==false)
		throw "He cannot fight, feed your monster.";
	points -= 10;
	arm.setWepAmmo(arm.getWepAmmo() - 10);

	cout << "I used my " << arm.getWepName() << ". I now have " << points << " points, and " << arm.getWepAmmo() << " ammo." << endl;
}

void Monster::relode() // relode your ammo
{
	if (points == 0)
		throw "You dont have points to relode him.";
	cout << "You can add no more than " << points << " ammo to " << name << "." << endl;
	cout << "how much ammo to you want to add ?" << endl;
	int relode;
	cin >> relode;
	while (checkPoints(points-relode)==false) {
		cout << "You dont have enough points for this, choose again: "<<endl;
			cin >> relode;
	}
	points = points - relode;
	arm.setWepAmmo(arm.getWepAmmo() + relode);
	cout << "I relode my " << arm.getWepName() << ". I now have " << points << " points, and " << arm.getWepAmmo() << " ammo." << endl;
}

bool Monster::checkPoints(int p)const //Points status for your monstor
{
	if (p < 0)
		return false;
	else
		return true;
}

