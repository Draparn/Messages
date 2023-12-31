#pragma once
#include "BaseApplicationState.h"


class AccountsMenu : public BaseApplicationState
{
public:
	AccountsMenu(std::shared_ptr<BaseInput> input_system, std::shared_ptr<BaseUI> ui_system, std::shared_ptr<AccountManager> account_manager);

	EMenus Run() const override;

};

