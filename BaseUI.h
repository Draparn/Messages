#pragma once
#include <string>

//The different types of "menu screens" that the application can show.
enum class EMenus
{
	eInvalidMenu = 0,

	eMainMenu,
	eLogInMenu,
	eCreateAccountMenu,
	eDeleteAccountMenu,
	eViewAccountsMenu,
	eLoggedInMenu,
	eSendMessageMenu,
	eReadUnreadMessagesMenu,
	eReadArchivedMessagesMenu
};


// The base interface for any UI that we implement.
class BaseUI
{
public:
	virtual void ShowMenu(EMenus menu, void* ptr = nullptr) = 0;
	virtual void ShowCustomMessage(const std::string& msg, bool alsoClearScreen = false) = 0;

};
