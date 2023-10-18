#include "ConsoleUI.h"
#include "Account.h"
#include <iostream>

#define PRINT(x) std::cout << x;	//TODO: Modify this to take a variable amount of args.


void ConsoleUI::ShowMenu(EMenus menu, void* ptr /* = nullptr */)
{
	system("cls");

	switch (menu)
	{
	case EMenus::eMainMenu:
		PRINT(MAIN_MENU_STR);
		break;

	case EMenus::eLogInMenu:
		PRINT(LOGIN_STR);
		break;

	case EMenus::eLoggedInMenu:
	{
		Account* account = static_cast<Account*>(ptr);

		//TODO: Replace this with the PRINT macro above when that has been expanded to take a variable amount of arguments.
		std::cout << "Welcome " << account->GetName() << "! You have " <<
			account->GetUnreadMessagesCount() << " unread message(s). What would you like to do?\n\n";

		PRINT(LOGGED_IN_STR);
		break;
	}

	case EMenus::eCreateAccountMenu:
		PRINT(CREATE_ACCOUNT_STR);
		break;

	case EMenus::eDeleteAccountMenu:
		PRINT(DELETE_ACCOUNT_STR);
		break;

	case EMenus::eViewAccountsMenu:
		PRINT(VIEW_ACCOUNTS_STR);
		break;

	case EMenus::eSendMessageMenu:
		PRINT(SEND_MESSAGE_STR);
		break;

		//These cases don't have any constant strings that need to be printed and will thusly be default.
		//case EMenus::ReadUnreadMessagesMenu:
		//case EMenus::ReadArchivedMessagesMenu:
	}
}

void ConsoleUI::ShowCustomMessage(const std::string& msg, bool alsoClearScreen /* = false */)
{
	if (alsoClearScreen)
		system("cls");

	PRINT(msg);
}

