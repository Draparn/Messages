#pragma once
#include <string>

class TextMessage
{
public:
	TextMessage() = delete;
	TextMessage(std::string& str);

private:
	std::string m_MessageString = "";
	bool m_IsUnread = false;

};
