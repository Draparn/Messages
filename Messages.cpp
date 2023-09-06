#include <iostream>
#include "ConsoleInput.h"
#include "ConsoleUI.h"
#include <string>


/*
* Create and Delete user accounts (no need for passwords).
* Login
* Send message to a specific user
* View own messages
* Track unread messages
*/

int main()
{
	//UI System. Interchangable by changing the class type in make_unique.
	std::unique_ptr<BaseUI> uiSystem = std::make_unique<ConsoleUI>();
	uiSystem->ShowMenu(EMenus::MainMenu);

	//Input system. Interchangable by changing the class type in make_unique.
	//Here because different UI systems might require a custom input system too.
	std::unique_ptr<BaseInput> inputSystem = std::make_unique<ConsoleInput>();

	char inputChar;
	bool quit = false;

	do
	{
		inputChar = inputSystem->GetChar();

		if (inputChar == 'x')
			quit = true;
		else
			uiSystem->ShowMenu(inputChar);	//TODO: Change this to call local functions instead that also handle the below logic


		switch (inputChar)
		{
		case Login:
		{
			break;
		}

		case CreateUser:
		{
			std::string str;
			inputSystem->GetLine(str);
			std::cout << "Your new User name is: " << str.c_str() << std::endl;
			break;
		}

		case DeleteUser:
			break;

		case ViewUsers:
			break;

		default:
			break;
		}

	} while (!quit);
}
