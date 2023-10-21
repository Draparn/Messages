#pragma once
#include "BaseUI.h"


//Console UI system for demonstration purposes. Can be swapped out by any other class inheriting from BaseUI.
class ConsoleUI : public BaseUI
{
public:
	void ShowMenu(EMenus menu, void* ptr = nullptr) override;	
	void ShowCustomMessage(const std::string& msg, bool alsoClearScreen = false) override;

private:
	//Constant strings that display the different "menus" in the console window.
	const char* MAIN_MENU_STR =
		"Welcome to Messages!\n\n"
		"1. Log in\n"
		"2. Accounts\n"
		"\nx. Exit.\n";

	const char* LOGIN_STR =
		"Account login\n\n"
		"Please enter your Account name: ";
	
	const char* LOGGED_IN_STR =
		"1. Send message.\n"
		"2. Read unread messages.\n"
		"3. Read archived messages.\n"
		"4. Log out.\n\n";
	
	const char* ACCOUNTS_STR =
		"What would you like to do?\n\n"
		"1. Create account.\n"
		"2. Delete account.\n"
		"3. View accounts.\n"
		"4. Back to Main menu.\n\n";

	const char* CREATE_ACCOUNT_STR =
		"Create new Account\n\n"
		"Please enter your desired Account name: ";
	
	const char* DELETE_ACCOUNT_STR =
		"Delete Account\n\n"
		"Please specify which Account name to delete: ";

	const char* VIEW_ACCOUNTS_STR =
		"These are the currently registered accounts:\n\n";

	const char* SEND_MESSAGE_STR =
		"Specify who you would like to send a message to: ";

};
