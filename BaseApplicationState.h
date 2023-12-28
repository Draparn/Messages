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
	virtual EMenus Run() const = 0;

protected:
	std::shared_ptr<BaseInput> m_InputSystem = nullptr;
	std::shared_ptr<BaseUI> m_UISystem = nullptr;
	std::shared_ptr<AccountManager> m_AccountManager = nullptr;
	
	static Account* m_CurrentlyLoggedInAccount;

	EMenus m_Tag = EMenus::InvalidMenu;

};