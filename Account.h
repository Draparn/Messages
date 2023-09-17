#pragma once
#include <string>
#include <vector>
#include "TextMessage.h"

class Account
{
public:
	Account() = delete;
	Account(std::string& name);
	bool operator == (const Account& acc) { return acc.m_AccountName == m_AccountName; }

	inline std::string& GetName() { return m_AccountName; }
	inline std::vector<TextMessage>& GetUnreadMessages() { return m_UnreadMessages; }
	inline std::size_t GetUnreadMessagesCount() { return m_UnreadMessages.size(); }

private:
	std::vector<TextMessage> m_UnreadMessages;
	std::vector<TextMessage> m_ArchivedMessages;

	std::string m_AccountName;

};
