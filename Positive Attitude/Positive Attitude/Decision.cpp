//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The Decision class is used whenever the player has to make a decision that will affect their story

#include "Decision.h"

Decision::Decision()
{

}

Decision::Decision(std::string decision1, std::string decision2, std::string decision3, std::string decision4)
{
	this->decision1 = decision1;
	this->decision2 = decision2;
	this->decision3 = decision3;
	this->decision4 = decision4;
}

Decision::~Decision()
{

}

int Decision::makeDecision()
{
	int choice = 0;
	int valid = 0;

	if (decision1 != "")
	{
		std::cout << "1. " << decision1 << std::endl;
	}
	if (decision2 != "")
	{
		std::cout << "2. " << decision2 << std::endl;
	}
	if (decision3 != "")
	{
		std::cout << "3. " << decision3 << std::endl;
	}
	if (decision4 != "")
	{
		std::cout << "4. " << decision4 << std::endl;
	}

	while (valid == 0)
	{

		std::cout << std::endl << "Your decision: ";
		std::cin >> choice;

		if (choice == 1 && decision1 != "")
		{
			valid = 1;
		}
		else if (choice == 2 && decision2 != "")
		{
			valid = 1;
		}
		else if (choice == 3 && decision3 != "")
		{
			valid = 1;
		}
		else if (choice == 4 && decision4 != "")
		{
			valid = 1;
		}
		else
		{
			std::cout << std::endl << "Invalid input. Try again." << std::endl;
		}
	}
	return choice;
}
