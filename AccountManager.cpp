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
	if (Account* acc = GetUserAccount(accountToDelete))
	{
		m_UserAccounts.erase(
			std::remove(m_UserAccounts.begin(), m_UserAccounts.end(), *acc),
			m_UserAccounts.end()
		);

		return true;
	}

	return false;
}

Account* AccountManager::GetUserAccount(std::string& accountName)
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
