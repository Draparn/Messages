#pragma once
#include <string>

enum class EMenus;

class BaseInput
{
public:
	virtual char GetChar() = 0;
	virtual bool GetSpecifiedChar(char c) = 0;
	virtual void GetLine(std::string& str) = 0;
	virtual void WaitForButtonPress(char c, EMenus& currentMenu, EMenus nextMenu) = 0;

};
