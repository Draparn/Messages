#include "AccountManager.h"


bool AccountManager::CreateUserAccount(std::string& desiredAccountName)
{
	if (GetUserAccount(desiredAccountName))
	{
		//Account name already exists
		return false;
	}

	m_UserAccounts.emplace_back(desiredAccountName);
	return true;
}

bool AccountManager::DeleteUserAccount(std::string& accountToDelete)
{
	//Coming soon.
}

Account* AccountManager::GetUserAccount(std::string& accountName)
{
	for (Account& account : m_UserAccounts)
	{
		if (account.GetName() == accountName)
		{
			return &account;
		}
	}

	return nullptr;
}
