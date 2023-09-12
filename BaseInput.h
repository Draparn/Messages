#pragma once
#include <string>

class BaseInput
{
public:
	virtual char GetChar() = 0;
	virtual bool GetSpecifiedChar(char c) = 0;
	virtual void GetLine(std::string& str) = 0;

};
