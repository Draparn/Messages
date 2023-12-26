#include <iostream>

#include "ConsoleInput.h"
#include "BaseUI.h"


char ConsoleInput::GetChar()
{
	m_Selection = getchar();

	//clear input stream
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return m_Selection;
}

bool ConsoleInput::GetSpecifiedChar(const char c)
{
	return tolower(GetChar()) == tolower(c);
}

void ConsoleInput::GetLine(std::string& str) const
{
	getline(std::cin, str);
}

void ConsoleInput::WaitForSpecifiedChar(const char c)
{
	while (!GetSpecifiedChar(c))
	{}
}
