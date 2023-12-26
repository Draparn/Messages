#pragma once
#include <string>

enum class EMenus;


class BaseInput
{
public:
	virtual char GetChar() = 0;
	virtual bool GetSpecifiedChar(const char c) = 0;
	virtual void GetLine(std::string& str) const = 0;
	virtual void WaitForSpecifiedChar(const char c) = 0;

};
