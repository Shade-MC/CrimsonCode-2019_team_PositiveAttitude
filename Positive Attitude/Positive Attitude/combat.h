#pragma once
#include "playerCharacter.h"

using std::string;

class Combat {
	
	public:
		Combat(int enemyId, playerCharacter * player = nullptr); 
		void takeTurn(int option);
		int motalKombat();
		void printMenu();
		int readMenu();
	private:
		
		Character enemy;
		playerCharacter * player;

};