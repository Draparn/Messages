#include "MainMenu.h"
#include "AccountsMenu.h"
#include "LoggedInMenu.h"


EMenus MainMenu::Run(Account*& currently_logged_in_account)
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

		if (currently_logged_in_account = m_AccountManager->GetUserAccount(str))
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
