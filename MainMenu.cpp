#include "MainMenu.h"
#include "AccountsMenu.h"
#include "LoggedInMenu.h"


MainMenu::MainMenu(std::shared_ptr<BaseInput> input_system, std::shared_ptr<BaseUI> ui_system, std::shared_ptr<AccountManager> account_manager)
{
	m_InputSystem = input_system;
	m_UISystem = ui_system;
	m_AccountManager = account_manager;
	m_Tag = EMenus::MainMenu;
}

EMenus MainMenu::Run()
{
	m_UISystem->ShowMenu(m_Tag);

	switch (tolower(m_InputSystem->GetChar()))
	{
	case 'x':	//Quit application
		return EMenus::ExitApplication;

	case '1':	//Log in
	{
		m_UISystem->ShowMenu(EMenus::LogInMenu);

		std::string str;
		m_InputSystem->GetLine(str);

		if (m_CurrentlyLoggedInAccount = m_AccountManager->GetUserAccount(str))
		{
			return EMenus::LoggedInMenu;
		}
		else
		{
			m_UISystem->ShowCustomMessage("Account not found.\n\n(b) Return to Main menu.\n");
			m_InputSystem->WaitForSpecifiedChar('b');
		}

		break;
	}

	case '2':	//Accounts
		return EMenus::AccountsMenu;
	}

	return m_Tag;
}
