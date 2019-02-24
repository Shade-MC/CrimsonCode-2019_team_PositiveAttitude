//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The character class keeps track of the stats of a weapon

#include "Weapon.h"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string name, bool type, int damage)
{
	this->name = name;
	this->type = type;
	this->damage = damage;
}

Weapon::~Weapon()
{

}

std::string Weapon::getName()
{
	return name;
}

bool Weapon::getType()
{
	return type;
}

int Weapon::getDamage()
{
	return damage;
}