#include "AccountsMenu.h"
#include "MainMenu.h"


AccountsMenu::AccountsMenu(std::shared_ptr<BaseInput> input_system, std::shared_ptr<BaseUI> ui_system, std::shared_ptr<AccountManager> account_manager)
{
	m_InputSystem = input_system;
	m_UISystem = ui_system;
	m_AccountManager = account_manager;
	m_Tag = EMenus::AccountsMenu;
}

EMenus AccountsMenu::Run()
{
	m_UISystem->ShowMenu(m_Tag);

	switch (tolower(m_InputSystem->GetChar()))
	{
	case '1':		//Create account
	{
		m_UISystem->ShowMenu(EMenus::CreateAccountMenu);

		std::string str;
		m_InputSystem->GetLine(str);

		if (m_AccountManager->CreateUserAccount(str))
		{
			m_UISystem->ShowCustomMessage("Account created successfully! Head to Main menu to log in.\n\n(b) Back to Account menu.\n");
		}
		else
		{
			m_UISystem->ShowCustomMessage("Error: An account with that name already exists.\n\n(b) Back to Account menu.\n");
		}

		m_InputSystem->WaitForSpecifiedChar('b');
		break;
	}

	case '2':		//Delete account
	{
		m_UISystem->ShowMenu(EMenus::DeleteAccountMenu);

		std::string str;
		m_InputSystem->GetLine(str);

		if (m_AccountManager->DeleteUserAccount(str))
		{
			m_UISystem->ShowCustomMessage("Account deleted successfully!\n\n(b) Back to Account menu.\n");
		}
		else
		{
			m_UISystem->ShowCustomMessage("Error: An account with that name does not exists.\n\n(b) Back to Account menu.\n");
		}

		m_InputSystem->WaitForSpecifiedChar('b');
		break;
	}

	case '3':		//View accounts
	{
		m_UISystem->ShowMenu(EMenus::ViewAccountsMenu);

		std::vector<Account>& allAccounts = m_AccountManager->GetAllUserAccounts();
		for (Account& acc : allAccounts)
		{
			m_UISystem->ShowCustomMessage(acc.GetName() + "\n");
		}

		m_UISystem->ShowCustomMessage("\n\n(b) Back to Account menu.\n");

		m_InputSystem->WaitForSpecifiedChar('b');
		break;
	}

	case '4':		//Back to Main Menu
		return EMenus::MainMenu;
	}

	return m_Tag;
}
