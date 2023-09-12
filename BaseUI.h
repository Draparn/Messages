#pragma once
#include <string>

//The different types of "menu screens" that the application can show.
enum EMenus : char
{
	InvalidMenu = 0,

	MainMenu = '0',
	LogInMenu = '1',
	CreateAccountMenu = '2',
	DeleteAccountMenu = '3',
	ViewAccountsMenu = '4',

	LoginWelcomeMenu,
	ViewMessageMenu
};


// The base interface for any UI that we implement.
class BaseUI
{
public:
	virtual EMenus ShowMenu(char input, void* ptr = nullptr) = 0;
	virtual void ShowApplicationMessage(const std::string& msg, bool alsoClearScreen = false) = 0;

};
