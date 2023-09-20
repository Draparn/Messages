#include "Account.h"
#include <algorithm>

Account::Account(std::string& name) :
	m_AccountName(name)
{}

void Account::AddNewMessage(std::string& message, std::string& sender)
{
	m_UnreadMessages.emplace_back(message, sender);
}

void Account::ArchiveReadMessages()
{
	//std::move the read messages into the archived vector.
	for (TextMessage& msg : m_UnreadMessages)
	{
		if (msg.GetHasBeenRead())
		{
			m_ArchivedMessages.emplace_back(std::move(msg));
		}
	}

	//Remove the read messages from the unread vector.
	m_UnreadMessages.erase(
		std::remove_if(m_UnreadMessages.begin(), m_UnreadMessages.end(), [](TextMessage& msg) { return msg.GetHasBeenRead(); }),
		m_UnreadMessages.end()
	);
}
