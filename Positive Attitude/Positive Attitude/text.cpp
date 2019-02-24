#include "text.h"

Text::Text(string input_string)
{
	mStringtobePrinted = input_string;
}

void Text::mPrintText() {
	system("cls");
	std::cout <<  mStringtobePrinted << std::endl << std::endl;
}

void Text::mPrintTextP() {
	system("cls");
	std::cout << mStringtobePrinted << std::endl << std::endl;
	system("pause");
}