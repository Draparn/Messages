#pragma once
#include <string>
#include <vector>
#include "TextMessage.h"

class Account
{
public:
	Account() = delete;
	Account(std::string& name);

	inline std::string& GetName() { return m_AccountName; }
	inline std::vector<TextMessage>& GetUnreadMessages() { return m_UnreadMessages; }

private:
	std::vector<TextMessage> m_UnreadMessages;
	std::vector<TextMessage> m_ArchivedMessages;

	std::string m_AccountName;

};
