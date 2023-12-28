#pragma once
#include <string>

//The different types of "menu screens" that the application can show.
 enum class [[nodiscard]] EMenus
{
	MainMenu,
	LogInMenu,
	AccountsMenu,
	CreateAccountMenu,
	DeleteAccountMenu,
	ViewAccountsMenu,
	LoggedInMenu,
	SendMessageMenu,
	ExitApplication,

	InvalidMenu
};


// The base interface for any UI that we implement.
class BaseUI
{
public:
	virtual void ShowMenu(EMenus menu, void* ptr = nullptr) const = 0;
	virtual void ShowCustomMessage(const std::string_view msg, bool alsoClearScreen = false) const = 0;

};
