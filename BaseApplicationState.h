#pragma once
#include <memory>

class Account;
class AccountManager;
class BaseInput;
class BaseUI;


class BaseApplicationState
{
public:
	virtual BaseApplicationState* Run(Account*& currently_logged_in_account) = 0;

protected:
	std::shared_ptr<BaseInput> m_InputSystem = nullptr;
	std::shared_ptr<BaseUI> m_UISystem = nullptr;
	std::shared_ptr<AccountManager> m_AccountManager = nullptr;

};

