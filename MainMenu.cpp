#include "MainMenu.h"
#include "BaseInput.h"
#include "BaseUI.h"
#include "AccountManager.h"
#include "LoggedIn.h"


BaseApplicationState* MainMenu::Run(Account*& currently_logged_in_account)
{
	m_UISystem->ShowMenu(EMenus::eMainMenu);

	char input = tolower(m_InputSystem->GetChar());

	switch (input)
	{
	case 'x':	//Quit application
		return nullptr;

	case '1':	//Log in
	{
		m_UISystem->ShowMenu(EMenus::eLogInMenu);

		std::string str;
		m_InputSystem->GetLine(str);

		if (currently_logged_in_account = m_AccountManager->GetUserAccount(str))
		{
			return new LoggedIn(m_InputSystem, m_UISystem, m_AccountManager);
		}
		else
		{
			m_UISystem->ShowCustomMessage("Account not found.\n\n(b) Return to Main menu.\n");
			m_InputSystem->WaitForSpecifiedChar('b');
		}

		break;
	}

	case '2':	//Create account
	case '3':	//Delete account
	case '4':	//View accounts
		//new accounts() current state
		break;
	}

	return this;
}
