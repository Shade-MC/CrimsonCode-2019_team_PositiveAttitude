#include "combat.h"


Combat::Combat(int enemyId, playerCharacter * player ){
	Weapon * weapon = new Weapon("weak", 0, 5);
	Weapon * weapon2 = new Weapon("weak", 0, 10);
	Weapon * weapon3 = new Weapon("weak", 1, 15);

	switch (enemyId) {
	case 1:
		enemy.setStats(20, 10, 20, 20, 20, 20, 20, weapon);

		break;
	case 2:
		enemy.setStats(20, 10, 20, 20, 20, 20, 20, weapon2);
		break;
	case 3:
		enemy.setStats(40, 40, 40, 15, 40, 40, 40, weapon3);
		break;

	}
	this->player = player;
}

void Combat::takeTurn(int option) {
	switch (option) {
	case 1:
		if (rand() * player->getAccuracy() > rand() * enemy.getEvasion()) {
			enemy.takeDamage(player->dealDamage(), &player->getWeapon());
		}
		if (rand() * player->getEvasion() < rand() * enemy.getAccuracy()) {
			player->takeDamage(enemy.dealDamage(), &enemy.getWeapon());
		}
	break;
	case 2:
		if (rand() * player->getAccuracy() > rand() * enemy.getEvasion()) {
			enemy.takeDamage(player->dealDamage(), player->getWeapon2());
		}
		if (rand() * player->getEvasion() < rand() * enemy.getAccuracy()) {
			player->takeDamage(enemy.dealDamage(), &enemy.getWeapon());
		}
		break;
	case 3:
		if (rand() * player->getEvasion() < rand() * enemy.getAccuracy()) {
			player->takeDamage(enemy.dealDamage() /2, &enemy.getWeapon());
		}
		break;
	case 4:
		if (rand() * player->getEvasion() < rand() * enemy.getAccuracy()) {
			player->takeDamage(enemy.dealDamage(), &enemy.getWeapon());
		}
		player->heal(rand() % 50);
		break;
	}
	
	
}

int Combat::motalKombat() {
	int win = 0;
	while (!player->isDead() && !enemy.isDead()) {
		system("cls");
		this->printMenu();
		this->takeTurn(this->readMenu());

	}
	if (enemy.isDead()) {
		win = 1;
	}
	else {
		win = 2;
	}
	return win;

}
void Combat::printMenu(){
	std::cout << "Enemy's Health: " << enemy.getCurrentHealth() << std::endl;
	std::cout << "Your Health:    " << player->getCurrentHealth() << std::endl;
	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "1. Melee Attack" << std::endl;
	std::cout << "2. Phaser Attack" << std::endl;
	std::cout << "3. Guard" << std::endl;
	std::cout << "4. Heal" << std::endl;
}
int Combat::readMenu() {
	int input = 0;

	std::cin >> input;
	if (input < 1 || input > 4) {
		do {
			std::cout << "Please enter valid input" << std::endl;
			std::cin >> input;
		} while (input < 1 || input > 4);
	}
	
	return input;
}