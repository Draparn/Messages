#pragma once
#include "BaseApplicationState.h"


class MainMenu : public BaseApplicationState
{
public:
	MainMenu(std::shared_ptr<BaseInput> input_system, std::shared_ptr<BaseUI> ui_system, std::shared_ptr<AccountManager> account_manager)
	{
		m_InputSystem = input_system;
		m_UISystem = ui_system;
		m_AccountManager = account_manager;
	};

	[[nodiscard]] BaseApplicationState* Run(Account*& currently_logged_in_account) override;

};

