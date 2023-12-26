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
	LoggedInMenu(std::shared_ptr<BaseInput> input_system, std::shared_ptr<BaseUI> ui_system, std::shared_ptr<AccountManager> account_manager);

	[[nodiscard]] EMenus Run() const override;

private:
	void ReadMessages(bool read_unread_msgs) const;
	void SortMessagesBy(std::vector<TextMessage>& vect, ESortType sort_type) const;

};
