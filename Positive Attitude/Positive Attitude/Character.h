//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The character class keeps track of the stats of a character

#include "Weapon.h"

class Character
{
protected:
	int maxHealth;
	int currentHealth;
	int strength;
	int defense;
	int magic;
	int magicResistance;
	int accuracy;
	int evasion;
	Weapon *weapon;

public:
	Character();
	Character(int maxHealth, int strength, int defense, int magic, int magicResistance, int accuracy, int evasion, Weapon *weapon);
	~Character();
	void setStats(int maxHealth, int strength, int defense, int magic, int magicResistance, int accuracy, int evasion, Weapon *weapon);
	void takeDamage(int damage, Weapon *weapon);
	int dealDamage();
	bool isDead();
	int getMaxHealth();
	int getCurrentHealth();
	int getStrength();
	int getDefense();
	int getMagic();
	int getMagicResistance();
	int getAccuracy();
	int getEvasion();
	Weapon getWeapon();

	//Weapon functions
	std::string getWeaponName();
	bool getWeaponType();
	int getWeaponDamage();
};
