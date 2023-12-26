#pragma once
#include "BaseUI.h"


//Console UI system for demonstration purposes. Can be swapped out by any other class inheriting from BaseUI.
class ConsoleUI : public BaseUI
{
public:
	void ShowMenu(EMenus menu, void* ptr = nullptr) const override;	
	void ShowCustomMessage(const std::string_view msg, bool alsoClearScreen = false) const override;

};
