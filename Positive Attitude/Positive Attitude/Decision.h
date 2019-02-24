//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The Decision class is used whenever the player has to make a decision that will affect their story
#pragma once
#include "text.h"


class Decision
{

private:
	std::string decision1;
	std::string decision2;
	std::string decision3;
	std::string decision4;

public:
	Decision();
	Decision::Decision(std::string decision1 = "", std::string decision2 = "", std::string decision3 = "", std::string decision4 = "");
	~Decision();
	int makeDecision();


};