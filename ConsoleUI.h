#pragma once
#include "BaseUI.h"


//Console UI system for demonstration purposes. Can be swapped out by any other class inheriting from BaseUI.
class ConsoleUI : public BaseUI
{
public:
	void ShowMenu(char menu) override;

private:
	void DisplayMainMenu();
	void DisplayLogin();
	void DisplayCreateUser();
	void DisplayDeleteUser();
	void DisplayViewUsers();

	//Constant strings that display the different menus in the console window.
	const char* MAIN_MENU_STR =
		"Welcome to Messages!\n\n"
		"1. User Login\n"
		"2. Create User\n"
		"3. Delete User\n"
		"4. View Users\n"
		"\nx. Exit.\n\n";

	const char* LOGIN_STR =
		"User login\n"
		"Please enter your User name: ";
	
	const char* CREATE_USER_STR =
		"Create new User\n"
		"Please enter your desired User name: ";
	
	const char* DELETE_USER_STR =
		"Delete User\n"
		"Please specify which User name to delete: ";

	const char* VIEW_USERS_STR =
		"These are the currently registered users:\n\n";

};
