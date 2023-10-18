#include "LoggedIn.h"
#include <algorithm>
#include "Account.h"
#include "AccountManager.h"
#include "BaseInput.h"
#include "BaseUI.h"
#include "MainMenu.h"

enum class ESortType
{
	SenderName,
	Timestamp
};
void SortMessagesBy(std::vector<TextMessage>& vect, ESortType sort_type)
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


BaseApplicationState* LoggedIn::Run(Account*& currently_logged_in_account)
{
	m_UISystem->ShowMenu(EMenus::eLoggedInMenu, currently_logged_in_account);

	switch (tolower(m_InputSystem->GetChar()))
	{
	case '1':	//Send message
	{
		m_UISystem->ShowMenu(EMenus::eSendMessageMenu);

		std::string str;
		m_InputSystem->GetLine(str);

		if (Account* receiver = m_AccountManager->GetUserAccount(str))
		{
			m_UISystem->ShowCustomMessage("Account found! Please enter your message:\n\n");

			m_InputSystem->GetLine(str);
			receiver->AddNewMessage(str, currently_logged_in_account->GetName());

			m_UISystem->ShowCustomMessage("Message successfully sent.\n\n(b) Back to your account.\n");
		}
		else
		{
			m_UISystem->ShowCustomMessage("\nError: No account with that name could be found.\n\n(b) Back to your account.\n");
		}

		m_InputSystem->WaitForSpecifiedChar('b');

		break;
	}

	case '2':	//Read unread messages
	{
		auto newMenu = ReadMessages(*currently_logged_in_account, true);
		if (newMenu != nullptr)
		{
			return newMenu;
		}

		break;
	}

	case '3':	//Read archived messages
	{
		auto newMenu = ReadMessages(*currently_logged_in_account, false);
		if (newMenu != nullptr)
		{
			return newMenu;
		}

		break;
	}

	case '4':	//Log out
		currently_logged_in_account = nullptr;
		return new MainMenu(m_InputSystem, m_UISystem, m_AccountManager);
	}

	return this;
}

BaseApplicationState* LoggedIn::ReadMessages(Account& currently_logged_in_account, bool read_unread_msgs)
{
	std::vector<TextMessage>& messages = read_unread_msgs ? currently_logged_in_account.GetUnreadMessages() : currently_logged_in_account.GetArchivedMessages();
	SortMessagesBy(messages, ESortType::Timestamp);

	if (messages.size() == 0)
	{
		m_UISystem->ShowCustomMessage("0 messages found.\n\n(b) Back to your account.\n", true);
		m_InputSystem->WaitForSpecifiedChar('b');
		return nullptr;
	}

	TextMessage* currentMessage;
	struct tm time;
	for (size_t i = 0; i < messages.size();)
	{
		currentMessage = &messages[i];
		currentMessage->SetHasBeenRead();

		m_UISystem->ShowCustomMessage(std::format("Displaying message {} of {}.\n\n", i + 1, messages.size()), true);
		m_UISystem->ShowCustomMessage(std::format("From: {}\t", currentMessage->GetSenderName()));
		localtime_s(&time, &currentMessage->GetTimeSent());
		m_UISystem->ShowCustomMessage(std::format("Message was sent 20{}/{}/{} {}:{}\n", time.tm_year - 100, time.tm_mon, time.tm_mday, time.tm_hour, time.tm_min));

		m_UISystem->ShowCustomMessage(currentMessage->GetMessageString());
		m_UISystem->ShowCustomMessage("\n\n(p) Read previous message.\t(n) Read next message.\t(r) Reply to message.\t(b) Back to your account.\n(s) Sort messages.\n\n");

		switch (tolower(m_InputSystem->GetChar()))
		{
		case 'p':	//previous message
			if (i > 0)
			{
				--i;
			}
			break;

		case 'n':	//next message
			if (i < messages.size() - 1)
			{
				++i;
			}
			break;

		case 'r':	//reply to message
		{
			if (Account* sender = m_AccountManager->GetUserAccount(currentMessage->GetSenderName()))
			{
				m_UISystem->ShowCustomMessage("Please enter your reply: ");

				std::string str;
				m_InputSystem->GetLine(str);

				sender->AddNewMessage(str, currently_logged_in_account.GetName());
				m_UISystem->ShowCustomMessage("\nMessage sent. Enter any key to continue.\n");
				m_InputSystem->GetChar();
			}
			else
			{
				m_UISystem->ShowCustomMessage(std::format("Account with name '{}' does not exist. Enter any key to continue.\n", currentMessage->GetSenderName()));
				m_InputSystem->GetChar();
			}
			break;
		}

		case 's':
		{
			m_UISystem->ShowCustomMessage("How would you like to sort them?\n(1) By time sent.\t(2) By sender.\n");
			char input;
			do
			{
				input = m_InputSystem->GetChar();
				SortMessagesBy(messages, input == '1' ? ESortType::Timestamp : ESortType::SenderName);
			} while (input != '1' && input != '2');

			break;
		}

		case 'b':	//back to previous menu
			i = messages.size();
			break;
		}
	}

	if (read_unread_msgs)
		currently_logged_in_account.ArchiveReadMessages();

	return new LoggedIn(m_InputSystem, m_UISystem, m_AccountManager);
}
