#define _CRT_SECURE_NO_WARNINGS
#ifndef _WEAPON
#define _WEAPON
#include <iostream>
#include <string>
using namespace std;
class Weapon
{
protected:
	string name;
	int ammo;
public:
	Weapon(string name1) : name(name1), ammo(100) {};
	string getWepName()const { return name; }const // get weapon name 
	int getWepAmmo()const { return ammo; }const // get weapon ammo
		void setWepAmmo(int NewAmmo) { ammo = NewAmmo; }// set weapon ammo
};
#endif 