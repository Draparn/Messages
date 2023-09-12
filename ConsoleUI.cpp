#include "ConsoleUI.h"
#include "Account.h"
#include <iostream>

#define PRINT(x) std::cout << x;	//TODO: Modify this to take a variable amount of args.


EMenus ConsoleUI::ShowMenu(char input, void* ptr /* = nullptr */)
{
	system("cls");

	switch (input)
	{
	case EMenus::MainMenu:
		return DisplayMainMenu();

	case EMenus::LogInMenu:
		return DisplayLogin();

	case EMenus::LoginWelcomeMenu:
		return DisplayLoginWelcome(ptr);

	case EMenus::ViewMessageMenu:
		return DisplayViewMessage();

	case EMenus::CreateAccountMenu:
		return DisplayCreateAccount();

	case EMenus::DeleteAccountMenu:
		return DisplayDeleteAccount();

	case EMenus::ViewAccountsMenu:
		return DisplayViewAccounts();

	default:
		return EMenus::InvalidMenu;
	}
}

void ConsoleUI::ShowApplicationMessage(const std::string& msg, bool alsoClearScreen /* = false */)
{
	if (alsoClearScreen)
		system("cls");

	PRINT(msg);
}


EMenus ConsoleUI::DisplayMainMenu()
{
	PRINT(MAIN_MENU_STR);
	return EMenus::MainMenu;
}

EMenus ConsoleUI::DisplayLogin()
{
	PRINT(LOGIN_STR);
	return EMenus::LogInMenu;
}

EMenus ConsoleUI::DisplayLoginWelcome(void* ptr)
{
	Account* account = static_cast<Account*>(ptr);
	
	//TODO: Clean this horrendous shite up...
	PRINT("Welcome ");
	PRINT(account->GetName());
	PRINT("!\n\n");

	return EMenus::LoginWelcomeMenu;
}

EMenus ConsoleUI::DisplayCreateAccount()
{
	PRINT(CREATE_ACCOUNT_STR);
	return EMenus::CreateAccountMenu;
}

EMenus ConsoleUI::DisplayDeleteAccount()
{
	PRINT(DELETE_ACCOUNT_STR);
	return EMenus::DeleteAccountMenu;
}

EMenus ConsoleUI::DisplayViewAccounts()
{
	PRINT(VIEW_ACCOUNTS_STR);
	return EMenus::ViewAccountsMenu;
}

EMenus ConsoleUI::DisplayViewMessage()
{
	return EMenus::ViewMessageMenu;
}
