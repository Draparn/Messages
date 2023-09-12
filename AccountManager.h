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

private:
	std::vector<Account> m_UserAccounts;	//TODO: Investigate which collection type to use.

};

