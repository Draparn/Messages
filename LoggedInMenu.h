#pragma once
#include <vector>

#include "BaseApplicationState.h"

enum class ESortType
{
	SenderName,
	Timestamp
};
class TextMessage;


class LoggedInMenu : public BaseApplicationState
{
public:
	LoggedInMenu(std::shared_ptr<BaseInput> input_system, std::shared_ptr<BaseUI> ui_system, std::shared_ptr<AccountManager> account_manager)
	{
		m_InputSystem = input_system;
		m_UISystem = ui_system;
		m_AccountManager = account_manager;
		m_Tag = EMenus::LoggedInMenu;
	};

	[[nodiscard]] EMenus Run(Account*& currently_logged_in_account) override;

private:
	void ReadMessages(Account& currently_logged_in_account, bool read_unread_msgs);
	void SortMessagesBy(std::vector<TextMessage>& vect, ESortType sort_type);

};

