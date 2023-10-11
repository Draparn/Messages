#pragma once
#include <string>
#include <vector>
#include "TextMessage.h"

enum class ESortType
{
	SenderName,
	Timestamp
};

class Account
{
public:
	Account() = delete;
	Account(std::string& name);
	bool operator == (const Account& acc) { return acc.m_AccountName == m_AccountName; }

	inline std::string& GetName() { return m_AccountName; }
	inline std::vector<TextMessage>& GetUnreadMessages() { return m_UnreadMessages; }
	inline std::vector<TextMessage>& GetArchivedMessages() { return m_ArchivedMessages; }
	inline std::size_t GetUnreadMessagesCount() { return m_UnreadMessages.size(); }

	void AddNewMessage(std::string& message, std::string& sender);
	void ArchiveReadMessages();
	void SortMessagesBy(std::vector<TextMessage>& vect, ESortType sort_type);

private:
	std::vector<TextMessage> m_UnreadMessages;
	std::vector<TextMessage> m_ArchivedMessages;

	std::string m_AccountName;

};
