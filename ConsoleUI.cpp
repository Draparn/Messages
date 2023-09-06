#include "ConsoleUI.h"
#include <iostream>

#define PRINT(x) std::cout << x;


//Clears the current console screen and prints the selected menu.
void ConsoleUI::ShowMenu(char menu)
{
	switch (menu)
	{
	case EMenus::MainMenu:
		DisplayMainMenu();
		break;

	case EMenus::Login:
		DisplayLogin();
		break;

	case EMenus::CreateUser:
		DisplayCreateUser();
		break;

	case EMenus::DeleteUser:
		DisplayDeleteUser();
		break;

	case EMenus::ViewUsers:
		DisplayViewUsers();
		break;

	default:
		PRINT("Error: No menu selection found."); //This should never happen.
		break;
	}
}


void ConsoleUI::DisplayMainMenu()
{
	system("cls");
	PRINT(MAIN_MENU_STR);
}

void ConsoleUI::DisplayLogin()
{
	system("cls");
	PRINT(LOGIN_STR);
	
}

void ConsoleUI::DisplayCreateUser()
{
	system("cls");
	PRINT(CREATE_USER_STR);
}

void ConsoleUI::DisplayDeleteUser()
{
	system("cls");
	PRINT(DELETE_USER_STR);
}

void ConsoleUI::DisplayViewUsers()
{
	system("cls");
	PRINT(VIEW_USERS_STR);
}
