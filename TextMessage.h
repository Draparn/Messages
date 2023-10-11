#pragma once
#include <string>
#include <chrono>

class TextMessage
{
public:
	TextMessage() = delete;
	TextMessage(std::string& str, std::string& sender, time_t current_time);

	bool operator == (const TextMessage& msg) { return &msg.m_MessageString == &m_MessageString; }

	inline std::string& GetMessageString() { return m_MessageString; }
	inline std::string& GetSenderName() { return m_Sender; }
	inline time_t& GetTimeSent() { return m_TimeSent; }
	inline bool HasBeenRead() { return m_HasBeenRead; }
	inline void SetHasBeenRead() { m_HasBeenRead = true; }

private:
	bool m_HasBeenRead = false;
	std::string m_MessageString = "";
	std::string m_Sender = "";
	time_t m_TimeSent;

};
