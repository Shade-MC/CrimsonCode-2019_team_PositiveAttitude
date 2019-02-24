#include "node.h"

int main(void) {
	Weapon * starter2 = new Weapon("Laser Cutlass", 0, 3);
	Weapon * starter = new Weapon("Phaser", 1, 3);
	playerCharacter * player = new playerCharacter(100,5,5,5,5,50,25,starter,starter2);

	Node * pCur = nullptr;
	std::ifstream input;

	srand((unsigned int)time(NULL));
	input.open("nodes.csv", std::fstream::in);

	pCur = createNodes(input, player);
	
	while (pCur != nullptr) {
		pCur = runNode(*pCur);
	}

}

