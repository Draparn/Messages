#include <iostream>
#include <unordered_map>

#include "AccountManager.h"
#include "AccountsMenu.h"
#include "ConsoleInput.h"
#include "ConsoleUI.h"
#include "LoggedInMenu.h"
#include "MainMenu.h"


int main()
{
	std::shared_ptr<BaseUI> uiSystem = std::make_shared<ConsoleUI>();
	std::shared_ptr<BaseInput> inputSystem = std::make_shared<ConsoleInput>();
	std::shared_ptr<AccountManager> accountManager = std::make_shared<AccountManager>();

	std::unordered_map<EMenus, std::shared_ptr<BaseApplicationState>> applicationMenus
	{
		{EMenus::MainMenu, std::make_shared<MainMenu>(inputSystem, uiSystem, accountManager)},
		{EMenus::LoggedInMenu, std::make_shared<LoggedInMenu>(inputSystem, uiSystem, accountManager)},
		{EMenus::AccountsMenu, std::make_shared<AccountsMenu>(inputSystem, uiSystem, accountManager)}
	};

	std::shared_ptr<BaseApplicationState> currentMenu = applicationMenus[EMenus::MainMenu];

	Account* currentlyLoggedInAccount = nullptr;

	{	//Add some accounts for us to use.
		std::string nameStr = "Johan";
		accountManager->CreateUserAccount(nameStr);
		nameStr = "Pete";
		accountManager->CreateUserAccount(nameStr);
		nameStr = "Harshal";
		accountManager->CreateUserAccount(nameStr);

		Account* harshalAcc = accountManager->GetUserAccount(nameStr);
		nameStr = "Pete";
		std::string msg = "A message string.";
		harshalAcc->AddNewMessage(msg, nameStr);
	}

	EMenus nextMenu;
	do
	{
		nextMenu = currentMenu->Run(currentlyLoggedInAccount);
		if (nextMenu == EMenus::ExitApplication)
			break;

		currentMenu = applicationMenus[nextMenu];
	} while (true);

}
