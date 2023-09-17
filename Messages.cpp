#include <iostream>
#include "ConsoleInput.h"
#include "ConsoleUI.h"
#include "AccountManager.h"
#include <string>


/*
* == Complete
x == Not implemented

* Create and Delete user accounts (no need for passwords).
* Login
X Send new message to a specific account
X Reply to a message in inbox
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
	void* customDataPtr = nullptr;

	EMenus currentMenu = EMenus::MainMenu;
	bool quit = false;


	//DEBUG, ONLY FOR TESTING!
	{
		std::string tmp = "One";
		accountManager->CreateUserAccount(tmp);
		tmp = "Two";
		accountManager->CreateUserAccount(tmp);
	}
	//DEBUG, ONLY FOR TESTING!

	do
	{
		//Render Menu
		uiSystem->ShowMenu(currentMenu, customDataPtr);

		//Get / Apply menu-dependent input
		switch (currentMenu)
		{
		case EMenus::MainMenu:
		{
			char input = tolower(inputSystem->GetChar());

			//Are we quitting the application?
			if (input == 'x')
			{
				quit = true;
				break;
			}

			switch (input)
			{
			case '1':
				currentMenu = EMenus::LogInMenu;
				break;

			case '2':
				currentMenu = EMenus::CreateAccountMenu;
				break;

			case '3':
				currentMenu = EMenus::DeleteAccountMenu;
				break;

			case '4':
				currentMenu = EMenus::ViewAccountsMenu;
				break;
			}

			break;
		}

		case EMenus::LogInMenu:
		{
			std::string str;

			inputSystem->GetLine(str);

			if (currentlyLoggedInAccount = accountManager->GetUserAccount(str))
			{
				currentMenu = EMenus::LoginWelcomeMenu;
				customDataPtr = currentlyLoggedInAccount;
			}
			else
			{
				uiSystem->ShowCustomMessage("Account not found.\n\nInput any key to try again.\t(b) Back to Main menu.\n");

				if (inputSystem->GetSpecifiedChar('b'))
				{
					currentMenu = EMenus::MainMenu;
					break;
				}
			}

			break;
		}

		case EMenus::LoginWelcomeMenu:
		{
			std::vector<TextMessage>& newMessages = currentlyLoggedInAccount->GetUnreadMessages();
			
			//TODO: Loop through all messages here and for each one, wait for input to read wither "(n) Next Message", "(p) Previous Message", (b) Back to Main menu etc.

			break;
		}

		case EMenus::CreateAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (accountManager->CreateUserAccount(str))
			{
				uiSystem->ShowCustomMessage("Account created successfully! Head to Main menu to log in.\n\n(b) Back to Main menu.\n");
			}
			else
			{
				uiSystem->ShowCustomMessage("Error: An account with that name already exists.\n\n(b) Back to Main menu.\n");
			}

			do
			{
				if (inputSystem->GetSpecifiedChar('b'))
				{
					currentMenu = EMenus::MainMenu;
					break;
				}
			} while (true);

			break;
		}

		case EMenus::DeleteAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (accountManager->DeleteUserAccount(str))
			{
				uiSystem->ShowCustomMessage("Account deleted successfully!\n\n(b) Back to Main menu.\n");
			}
			else
			{
				uiSystem->ShowCustomMessage("Error: An account with that name does not exists.\n\n(b) Back to Main menu.\n");
			}

			do
			{
				if (inputSystem->GetSpecifiedChar('b'))
				{
					currentMenu = EMenus::MainMenu;
					break;
				}
			} while (true);

			break;
		}

		case EMenus::ViewAccountsMenu:
		{
			std::vector<Account>& allAccounts = accountManager->GetAllUserAccounts();
			for (Account& acc : allAccounts)
			{
				uiSystem->ShowCustomMessage(acc.GetName()+"\n");
			}

			uiSystem->ShowCustomMessage("\n\n(b) Back to Main menu.\n");

			do
			{
				if (inputSystem->GetSpecifiedChar('b'))
				{
					currentMenu = EMenus::MainMenu;
					break;
				}
				else
				{
					int wtf = 5;
				}
			} while (true);

			break;
		}

		default:
			break;
		}

	} while (quit == false);

}
