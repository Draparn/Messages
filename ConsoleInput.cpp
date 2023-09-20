#include "ConsoleInput.h"
#include "BaseUI.h"
#include <iostream>


char ConsoleInput::GetChar()
{
	m_Selection = getchar();

	ClearInputStream();
	return m_Selection;
}

bool ConsoleInput::GetSpecifiedChar(char c)
{
	return tolower(GetChar()) == tolower(c);
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

void ConsoleInput::WaitForButtonPress(char c, EMenus& currentMenu, EMenus nextMenu)
{
	do
	{
		if (GetSpecifiedChar(c))
		{
			currentMenu = nextMenu;
			break;
		}
	} while (true);
}
