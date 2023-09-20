#include "TextMessage.h"

TextMessage::TextMessage(std::string& str, std::string& sender) :
	m_HasBeenRead(false), m_MessageString(str), m_Sender(sender)
{}
