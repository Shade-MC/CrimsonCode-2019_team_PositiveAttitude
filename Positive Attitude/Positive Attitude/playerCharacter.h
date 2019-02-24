//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The character class keeps track of the stats of the player character


#include "Character.h"

class playerCharacter : public Character
{
	private:
		int experience = 0;
		int level = 0;
		Weapon * weapon2;
	public:
		playerCharacter();
		playerCharacter(int maxHealth, int strength, int defense, int magic, int magicResistance, int accuracy, int evasion, Weapon *weapon, Weapon *weapon2);
		~playerCharacter();
		void addExperience(int newExperience);
		Weapon * getWeapon2();
		int getExperience();
		void levelUp();
		int getLevel();
		void heal(int amount);
};