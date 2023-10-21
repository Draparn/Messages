#pragma once
#include <vector>
#include <string>

#include "Account.h"


class AccountManager
{
public:
	bool CreateUserAccount(std::string& desiredAccountName);
	bool DeleteUserAccount(std::string& accountToDelete);
	Account* GetUserAccount(std::string& accountName);
	inline std::vector<Account>& GetAllUserAccounts() { return m_UserAccounts; }

private:
	std::vector<Account> m_UserAccounts;

};

