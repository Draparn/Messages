#include <iostream>
#include "AccountManager.h"
#include "ConsoleInput.h"
#include "ConsoleUI.h"
#include "MainMenu.h"


int main()
{
	//UI System. Interchangable by changing the class type in make_unique.
	std::shared_ptr<BaseUI> uiSystem = std::make_shared<ConsoleUI>();

	//Input system. Interchangable by changing the class type in make_unique.
	//Here because different UI systems might require a custom input system too.
	std::shared_ptr<BaseInput> inputSystem = std::make_shared<ConsoleInput>();

	std::shared_ptr<AccountManager> accountManager = std::make_shared<AccountManager>();

	std::shared_ptr<BaseApplicationState> currentMennu = std::make_shared<MainMenu>(inputSystem, uiSystem, accountManager);

	Account* currentlyLoggedInAccount = nullptr;

	{	//Add some accounts for us to use.
		std::string johanStr = "Johan";
		accountManager->CreateUserAccount(johanStr);
		std::string PeteStr = "Pete";
		accountManager->CreateUserAccount(PeteStr);
		std::string harshalStr = "Harshal";
		accountManager->CreateUserAccount(harshalStr);

		Account* johAcc = accountManager->GetUserAccount(johanStr);
		std::string msg = "A message string.";
		johAcc->AddNewMessage(msg, PeteStr);
	}

	do
	{
		//Render Menu
		//uiSystem->ShowMenu(currentMenu, customDataPtr);

		auto newMenu = currentMennu->Run(currentlyLoggedInAccount);
		if (newMenu == nullptr)	//Quit application
			break;

		if (currentMennu.get() != newMenu)
		{
			currentMennu.reset(newMenu);
		}

		//TEMP, REMOVE THIS!!
		continue;
		//TEMP, REMOVE THIS!!


		//Get/Apply input depending on menu
		switch (EMenus::eCreateAccountMenu)
		{

		case EMenus::eCreateAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (accountManager->CreateUserAccount(str))
			{
				uiSystem->ShowCustomMessage("Account created successfully! Head to Main menu to log in.\n\n(b) Back to Main menu.\n");
			}
			else
			{
				uiSystem->ShowCustomMessage("Error: An account with that name already exists.\n\n(b) Back to Main menu.\n");
			}

			inputSystem->WaitForSpecifiedChar('b');
			break;
		}

		case EMenus::eDeleteAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (accountManager->DeleteUserAccount(str))
			{
				uiSystem->ShowCustomMessage("Account deleted successfully!\n\n(b) Back to Main menu.\n");
			}
			else
			{
				uiSystem->ShowCustomMessage("Error: An account with that name does not exists.\n\n(b) Back to Main menu.\n");
			}

			inputSystem->WaitForSpecifiedChar('b');
			break;
		}

		case EMenus::eViewAccountsMenu:
		{
			std::vector<Account>& allAccounts = accountManager->GetAllUserAccounts();
			for (Account& acc : allAccounts)
			{
				uiSystem->ShowCustomMessage(acc.GetName() + "\n");
			}

			uiSystem->ShowCustomMessage("\n\n(b) Back to Main menu.\n");

			inputSystem->WaitForSpecifiedChar('b');
			break;
		}

		}

	} while (true);

}
