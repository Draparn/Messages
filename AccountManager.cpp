#include "AccountManager.h"


bool AccountManager::CreateUserAccount(const std::string_view desiredAccountName)
{
	if (GetUserAccount(desiredAccountName))
	{
		//Account name already exists
		return false;
	}

	m_UserAccounts.emplace_back(desiredAccountName);
	return true;
}

bool AccountManager::DeleteUserAccount(const std::string_view accountToDelete)
{
	if (Account* acc = GetUserAccount(accountToDelete))
	{
		std::erase(m_UserAccounts, accountToDelete);
		return true;
	}

	return false;
}

Account* AccountManager::GetUserAccount(const std::string_view accountName)
{
	for (auto& account : m_UserAccounts)
	{
		if (account.GetName() == accountName)
		{
			return &account;
		}
	}

	return nullptr;
}
