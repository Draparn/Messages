#pragma once
#include <memory>

#include "AccountManager.h"
#include "BaseInput.h"
#include "BaseUI.h"

class Account;
class AccountManager;
class BaseInput;
class BaseUI;


class BaseApplicationState
{
public:
	[[nodiscard]] virtual EMenus Run(Account*& currently_logged_in_account) = 0;
	inline EMenus GetTag() { return m_Tag; };

protected:
	std::shared_ptr<BaseInput> m_InputSystem = nullptr;
	std::shared_ptr<BaseUI> m_UISystem = nullptr;
	std::shared_ptr<AccountManager> m_AccountManager = nullptr;
	EMenus m_Tag = EMenus::InvalidMenu;

};

