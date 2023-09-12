#include <iostream>
#include "ConsoleInput.h"
#include "ConsoleUI.h"
#include "AccountManager.h"
#include <string>


/*
* Create and Delete user accounts (no need for passwords).
* Login
* Send message to a specific account
* View own messages
* Track unread messages
*/


int main()
{
	//UI System. Interchangable by changing the class type in make_unique.
	std::unique_ptr<BaseUI> uiSystem = std::make_unique<ConsoleUI>();

	//Input system. Interchangable by changing the class type in make_unique.
	//Here because different UI systems might require a custom input system too.
	std::unique_ptr<BaseInput> inputSystem = std::make_unique<ConsoleInput>();

	std::unique_ptr<AccountManager> accountManager = std::make_unique<AccountManager>();
	Account* currentlyLoggedInAccount = nullptr;

	EMenus currentMenu = uiSystem->ShowMenu(EMenus::MainMenu);
	bool quit = false;

	do
	{
		switch (currentMenu)
		{
		case MainMenu:
		{
			do
			{
				char input = tolower(inputSystem->GetChar());

				//Are we quitting the application?
				if (input == 'x')
				{
					quit = true;
					break;
				}

				currentMenu = uiSystem->ShowMenu(input);

				//If no valid menu choice was put in, reprint the main menu.
				if (currentMenu == EMenus::InvalidMenu)
				{
					currentMenu = uiSystem->ShowMenu(EMenus::MainMenu);
				}

			} while (currentMenu == EMenus::InvalidMenu);

			break;
		}

		case LogInMenu:
		{
			std::string str;

			do
			{
				inputSystem->GetLine(str);

				if (currentlyLoggedInAccount = accountManager->GetUserAccount(str))
				{
					currentMenu = uiSystem->ShowMenu(EMenus::LoginWelcomeMenu, currentlyLoggedInAccount);
				}
				else
				{
					uiSystem->ShowApplicationMessage("Account not found.\n\n(b) Back to Main menu.\n", true);

					char inputChar;
					do
					{
						if (inputSystem->GetSpecifiedChar('b'))
						{
							currentMenu = uiSystem->ShowMenu(EMenus::MainMenu);
							break;
						}
					} while (true);
				}

			} while (currentMenu == EMenus::InvalidMenu);

			break;
		}

		case LoginWelcomeMenu:
		{
			std::vector<TextMessage>& newMessages = currentlyLoggedInAccount->GetUnreadMessages();
			
			//TODO: Loop through messages here and flip their "IsUnread" bool once they are.

			break;
		}

		case CreateAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (accountManager->CreateUserAccount(str))
			{
				uiSystem->ShowApplicationMessage("Account creation successful! Head to Main menu to log in.\n\n(b) Back to Main menu.\n");

				char inputChar;
				do
				{
					if (inputSystem->GetSpecifiedChar('b'))
					{
						currentMenu = uiSystem->ShowMenu(EMenus::MainMenu);
						break;
					}

					/*inputChar = inputSystem->GetChar();

					if (inputChar == 'b' || inputChar == 'B')
					{
						currentMenu = uiSystem->ShowMenu(EMenus::MainMenu);
						break;
					}*/
				} while (true);
			}
			else
			{
				//Account name already existed.
			}

			break;
		}

		case DeleteAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);
			
			if (accountManager->DeleteUserAccount(str))
			{

			}
			else
			{

			}

			break;
		}

		case ViewAccountsMenu:
		{

			break;
		}

		case ViewMessageMenu:
		{

			break;
		}

		default:
			break;
		}

	} while (quit == false);

}
