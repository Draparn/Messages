#pragma once
#include <string>
#include <chrono>


class TextMessage
{
public:
	TextMessage() = delete;
	TextMessage(std::string_view str, std::string_view sender, time_t current_time);
	
	inline const std::string& GetMessageString() const { return m_MessageString; }
	inline const std::string& GetSenderName() const { return m_Sender; }
	inline const time_t& GetTimeSent() const { return m_TimeSent; }
	inline bool HasBeenRead() const { return m_HasBeenRead; }
	inline void SetHasBeenRead() { m_HasBeenRead = true; }

private:
	bool m_HasBeenRead = false;
	std::string m_MessageString = "";
	std::string m_Sender = "";
	time_t m_TimeSent;

};
