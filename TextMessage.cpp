#include "TextMessage.h"


TextMessage::TextMessage(std::string_view str, std::string_view sender, time_t current_time) :
	m_HasBeenRead(false), m_MessageString(str), m_Sender(sender), m_TimeSent(current_time)
{}
