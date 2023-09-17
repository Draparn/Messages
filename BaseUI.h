#pragma once
#include <string>

//The different types of "menu screens" that the application can show.
enum class EMenus
{
	InvalidMenu = 0,

	MainMenu,
	LogInMenu,
	CreateAccountMenu,
	DeleteAccountMenu,
	ViewAccountsMenu,

	LoginWelcomeMenu
};


// The base interface for any UI that we implement.
class BaseUI
{
public:
	virtual void ShowMenu(EMenus menu, void* ptr = nullptr) = 0;
	virtual void ShowCustomMessage(const std::string& msg, bool alsoClearScreen = false) = 0;

};
