#include "Account.h"
#include <algorithm>

Account::Account(std::string& name) :
	m_AccountName(name)
{}

void Account::AddNewMessage(std::string& message, std::string& sender)
{
	m_UnreadMessages.emplace_back(
		message,
		sender,
		std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
	);
}

void Account::ArchiveReadMessages()
{
	for (TextMessage& msg : m_UnreadMessages)
	{
		if (msg.HasBeenRead())
		{
			m_ArchivedMessages.emplace_back(msg);
		}
	}

	//Remove the read messages from the unread vector using std::remove_if
	/*m_UnreadMessages.erase(
		std::remove_if(m_UnreadMessages.begin(), m_UnreadMessages.end(), [](TextMessage& msg) { return msg.HasBeenRead(); }),
		m_UnreadMessages.end()
	);*/


	//Purposefully ugly solution. I kept the modern cleaner solution above.
	//Remove the read messages by manually moving the last element over and popping the back. This unsorts the vector, is a pain in the @ss and reads horribly.
	for (auto it = m_UnreadMessages.begin(); it != m_UnreadMessages.end(); )
	{
		if (it->HasBeenRead())
		{
			*it = *(m_UnreadMessages.end() - 1);
			m_UnreadMessages.pop_back();

			if (m_UnreadMessages.empty())
			{
				break;
			}

			continue;
		}

		it++;
	}

	SortMessagesBy(m_UnreadMessages, ESortType::Timestamp);

}

void Account::SortMessagesBy(std::vector<TextMessage>& vect, ESortType sort_type)
{
	if (vect.empty())
		return;

	switch (sort_type)
	{
	case ESortType::SenderName:
		std::sort(
			vect.begin(),
			vect.end(),
			[](TextMessage& a, TextMessage& b) { return a.GetSenderName() < b.GetSenderName(); }
		);
		break;

	case ESortType::Timestamp:
		std::sort(
			vect.begin(),
			vect.end(),
			[](TextMessage& a, TextMessage& b) { return a.GetTimeSent() < b.GetTimeSent(); }
		);
		break;
	}
}
