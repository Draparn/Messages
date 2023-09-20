#pragma once
#include <string>

class TextMessage
{
public:
	TextMessage() = delete;
	TextMessage(std::string& str, std::string& sender);

	bool operator == (const TextMessage& msg) { return &msg.m_MessageString == &m_MessageString; }

	inline std::string& GetMessageString() { return m_MessageString; }
	inline std::string& GetSenderName() { return m_Sender; }
	inline bool GetHasBeenRead() { return m_HasBeenRead; }
	inline void SetHasBeenRead() { m_HasBeenRead = true; }

private:
	bool m_HasBeenRead = false;
	std::string m_MessageString = "";
	std::string m_Sender = "";

};
