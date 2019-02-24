#pragma once
#include "positveAttitude.h"

using std::string;

class Text
{
public:
	void mPrintText(); //prints out text from file, this makes up the adventure events, possibly combat prompts
	void mPrintTextP();

	Text(string input_string = ""); //constructor function
	
private:
	string mStringtobePrinted; //this is what will be printed
};