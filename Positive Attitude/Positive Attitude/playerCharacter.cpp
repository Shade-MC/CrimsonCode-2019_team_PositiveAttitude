//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The character class keeps track of the stats of the player character

#include "playerCharacter.h"

playerCharacter::playerCharacter()
{

}

playerCharacter::playerCharacter(int maxHealth, int strength, int defense, int magic, int magicResistance, int accuracy, int evasion, Weapon *weapon, Weapon *weapon2)
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
	this->weapon2 = weapon2;
}

playerCharacter::~playerCharacter()
{

}

void playerCharacter::addExperience(int newExperience)
{
	experience = experience + newExperience;
}

int playerCharacter::getExperience()
{
	return experience;
}

void playerCharacter::levelUp()
{
	level++;
}

int playerCharacter::getLevel()
{
	return level;
}
void playerCharacter::heal(int amount) {
	currentHealth += amount;
}
Weapon * playerCharacter::getWeapon2() {
	return weapon2;
}