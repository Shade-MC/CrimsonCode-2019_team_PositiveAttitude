//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The character class keeps track of the stats of a weapon

#include "Decision.h"

class Weapon
{
	private:
		std::string name;
		bool type;
		int damage;
	
	public:
		Weapon();
		Weapon(std::string name, bool type, int damage);
		~Weapon();
		std::string getName();
		bool getType();
		int getDamage();
};