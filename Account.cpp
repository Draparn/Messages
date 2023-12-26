#include <algorithm>

#include "Account.h"


Account::Account(const std::string_view name) : m_AccountName(name)
{}

void Account::AddNewMessage(std::string_view message, std::string_view sender)
{
	m_UnreadMessages.emplace_back(
		message,
		sender,
		std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
	);
}

void Account::ArchiveReadMessages()
{
	for (TextMessage& msg : m_UnreadMessages)
	{
		if (msg.HasBeenRead())
		{
			m_ArchivedMessages.emplace_back(msg);
		}
	}
	
	std::erase_if(m_UnreadMessages, [](TextMessage& msg) { return msg.HasBeenRead(); });

}
