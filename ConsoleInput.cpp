#include "ConsoleInput.h"
#include "BaseUI.h"
#include <iostream>


char ConsoleInput::GetChar()
{
	m_Selection = getchar();

	ClearInputStream();
	return m_Selection;
}

void ConsoleInput::GetLine(std::string& str)
{
	getline(std::cin, str);
}

void ConsoleInput::ClearInputStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
