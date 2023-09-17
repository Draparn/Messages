#include "ConsoleUI.h"
#include "Account.h"
#include <iostream>

#define PRINT(x) std::cout << x;	//TODO: Modify this to take a variable amount of args.


void ConsoleUI::ShowMenu(EMenus menu, void* ptr /* = nullptr */)
{
	system("cls");

	switch (menu)
	{
	case EMenus::MainMenu:
		PRINT(MAIN_MENU_STR);
		break;

	case EMenus::LogInMenu:
		PRINT(LOGIN_STR);
		break;

	case EMenus::LoginWelcomeMenu:
	{
		Account* account = static_cast<Account*>(ptr);

		//TODO: Replace this with the PRINT macro above when that has been expanded to take a variable amount of arguments.
		std::cout << "Welcome " << account->GetName() << "! You have "
			<< account->GetUnreadMessagesCount() << " unread messages.\n";

		break;
	}

	case EMenus::CreateAccountMenu:
		PRINT(CREATE_ACCOUNT_STR);
		break;

	case EMenus::DeleteAccountMenu:
		PRINT(DELETE_ACCOUNT_STR);
		break;

	case EMenus::ViewAccountsMenu:
		PRINT(VIEW_ACCOUNTS_STR);
		break;

	default:
		break;
	}
}

void ConsoleUI::ShowCustomMessage(const std::string& msg, bool alsoClearScreen /* = false */)
{
	if (alsoClearScreen)
		system("cls");

	PRINT(msg);
}

