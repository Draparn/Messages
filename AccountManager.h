#pragma once
#include <vector>
#include <string>

#include "Account.h"


class AccountManager
{
public:
	bool CreateUserAccount(const std::string_view desiredAccountName);
	bool DeleteUserAccount(const std::string_view accountToDelete);
	Account* GetUserAccount(const std::string_view accountName);
	inline const std::vector<Account>& GetAllUserAccounts() { return m_UserAccounts; }

private:
	std::vector<Account> m_UserAccounts;

};

