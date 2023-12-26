#pragma once
#include "BaseInput.h"


//Console input system that's utilizing iostream. Can be swapped out by any other class inheriting from BaseInput.
class ConsoleInput : public BaseInput
{
public:
	//Returns a single char value taken from input stream using getchar().
	char GetChar() override;

	//Returns whether the user entered the specified character or not.
	bool GetSpecifiedChar(const char c) override;

	//Sets a std::string ref using getline()
	void GetLine(std::string& str) const override;
	
	//Loops until a specified character is put in.
	void WaitForSpecifiedChar(const char c) override;
	
private:
	char m_Selection = '.';

};
