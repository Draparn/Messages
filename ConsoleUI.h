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
		"2. Create Account\n"
		"3. Delete Account\n"
		"4. View Accounts\n"
		"\nx. Exit.\n\n";

	const char* LOGIN_STR =
		"Account login\n\n"
		"Please enter your Account name: ";
	
	const char* LOGGED_IN_STR =
		"1. Send message.\n"
		"2. Read new messages.\n"
		"3. Read archived messages.\n"
		"4. Log out.\n\n";
	
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
