//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The character class keeps track of the stats of a character

#include "Character.h"

Character::Character()
{

}

Character::Character(int maxHealth, int strength, int defense, int magic, int magicResistance, int accuracy, int evasion, Weapon *weapon)
{
	this->maxHealth = maxHealth;
	this->currentHealth = maxHealth;
	this->strength = strength;
	this->defense = defense;
	this->magic = magic;
	this->magicResistance = magicResistance;
	this->accuracy = accuracy;
	this->evasion = evasion;
	this->weapon = weapon;
}

Character::~Character()
{

}

void Character::takeDamage(int damage, Weapon *weapon)
{
	if (weapon->getType() == 0) {
		if (this->defense < damage ) {
			currentHealth = currentHealth - damage + this->defense;
		}
	}
	else {
		if (this->magicResistance < damage) {
			currentHealth = currentHealth - damage + magicResistance;
		}
	}
	currentHealth = currentHealth - damage;
}

void Character::setStats(int maxHealth, int strength, int defense, int magic, int magicResistance, int accuracy, int evasion, Weapon *weapon) {
	this->maxHealth = maxHealth;
	this->currentHealth = maxHealth;
	this->strength = strength;
	this->defense = defense;
	this->magic = magic;
	this->magicResistance = magicResistance;
	this->accuracy = accuracy;
	this->evasion = evasion;
	this->weapon = weapon;


}

int Character::dealDamage() {
	int damage = 0;
	damage = strength + weapon->getDamage() + rand() % 2;
	return damage;
}
bool Character::isDead()
{
	if (currentHealth <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Character::getMaxHealth()
{
	return maxHealth;
}

int Character::getCurrentHealth()
{
	return currentHealth;
}

int Character::getStrength()
{
	return strength;
}

int Character::getDefense()
{
	return defense;
}

int Character::getMagic()
{
	return magic;
}

int Character::getMagicResistance()
{
	return magicResistance;
}

int Character::getAccuracy()
{
	return accuracy;
}

int Character::getEvasion()
{
	return evasion;
}

Weapon Character::getWeapon()
{
	return *weapon;
}

//Weapon functions
std::string Character::getWeaponName()
{
	return this->getWeapon().getName();
}

bool Character::getWeaponType()
{
	return this->getWeapon().getType();
}

int Character::getWeaponDamage()
{
	return this->getWeapon().getDamage();
}