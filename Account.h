#pragma once
#include <string>
#include <vector>

#include "TextMessage.h"


class Account
{
public:
	Account() = delete;
	Account(const std::string_view name);
	bool operator == (const Account& acc) { return acc.m_AccountName == m_AccountName; }

	inline const std::string& GetName() const { return m_AccountName; }
	inline std::vector<TextMessage>& GetUnreadMessages() { return m_UnreadMessages; }
	inline std::vector<TextMessage>& GetArchivedMessages() { return m_ArchivedMessages; }
	inline const std::size_t GetUnreadMessagesCount() const { return m_UnreadMessages.size(); }

	void AddNewMessage(std::string& message, std::string_view sender);
	void ArchiveReadMessages();

private:
	std::vector<TextMessage> m_UnreadMessages;
	std::vector<TextMessage> m_ArchivedMessages;

	std::string m_AccountName;

};
