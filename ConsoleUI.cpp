#include <print>

#include "ConsoleUI.h"
#include "Account.h"


void ConsoleUI::ShowMenu(EMenus menu, void* ptr /* = nullptr */)
{
	system("cls");

	switch (menu)
	{
	case EMenus::MainMenu:
		std::print(
			"Welcome to Messages!\n\n"
			"1. Log in\n"
			"2. Accounts\n"
			"\nx. Exit.\n");
		break;

	case EMenus::LogInMenu:
		std::print(
			"Account login\n\n"
			"Please enter your Account name: ");
		break;

	case EMenus::LoggedInMenu:
	{
		Account* account = static_cast<Account*>(ptr);

		std::print("Welcome {0}! You have {1} unread message(s). What would you like to do?\n\n", account->GetName(), account->GetUnreadMessagesCount());
		std::print(
			"1. Send message.\n"
			"2. Read unread messages.\n"
			"3. Read archived messages.\n"
			"4. Log out.\n\n");
		break;
	}

	case EMenus::AccountsMenu:
		std::print(
			"What would you like to do?\n\n"
			"1. Create account.\n"
			"2. Delete account.\n"
			"3. View accounts.\n"
			"4. Back to Main menu.\n\n");
		break;

	case EMenus::CreateAccountMenu:
		std::print(
			"Create new Account\n\n"
			"Please enter your desired Account name: ");
		break;

	case EMenus::DeleteAccountMenu:
		std::print(
			"Delete Account\n\n"
			"Please specify which Account name to delete: ");
		break;

	case EMenus::ViewAccountsMenu:
		std::print("These are the currently registered accounts:\n\n");
		break;

	case EMenus::SendMessageMenu:
		std::print("Specify who you would like to send a message to: ");
		break;

	}
}

void ConsoleUI::ShowCustomMessage(const std::string& msg, bool alsoClearScreen /* = false */)
{
	if (alsoClearScreen)
		system("cls");

	std::print("{}", msg);
}

