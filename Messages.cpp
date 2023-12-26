#include <iostream>
#include <unordered_map>

#include "AccountManager.h"
#include "AccountsMenu.h"
#include "ConsoleInput.h"
#include "ConsoleUI.h"
#include "LoggedInMenu.h"
#include "MainMenu.h"


Account* BaseApplicationState::m_CurrentlyLoggedInAccount = nullptr;

int main()
{
	auto uiSystem = std::make_shared<ConsoleUI>();
	auto inputSystem = std::make_shared<ConsoleInput>();
	auto accountManager = std::make_shared<AccountManager>();

	std::unordered_map<EMenus, std::shared_ptr<BaseApplicationState>> applicationMenus
	{
		{EMenus::MainMenu, std::make_shared<MainMenu>(inputSystem, uiSystem, accountManager)},
		{EMenus::LoggedInMenu, std::make_shared<LoggedInMenu>(inputSystem, uiSystem, accountManager)},
		{EMenus::AccountsMenu, std::make_shared<AccountsMenu>(inputSystem, uiSystem, accountManager)}
	};

	auto currentMenu = applicationMenus[EMenus::MainMenu];
	EMenus nextMenu;

	{	//Add some accounts for us to use.
		accountManager->CreateUserAccount("Johan");
		accountManager->CreateUserAccount("Pete");
		accountManager->CreateUserAccount("Harshal");

		Account* harshalAcc = accountManager->GetUserAccount("Harshal");
		harshalAcc->AddNewMessage("A message string.", "Pete");
	}

	while ((nextMenu = currentMenu->Run()) != EMenus::ExitApplication)
	{
		currentMenu = applicationMenus[nextMenu];
	}
}
