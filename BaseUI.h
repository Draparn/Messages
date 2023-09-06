#pragma once

//The different types of "menu screens" that the application can show.
enum EMenus : char
{
	MainMenu = '0',
	Login,
	CreateUser,
	DeleteUser,
	ViewUsers
};


// The base interface for any UI that we implement.
class BaseUI
{
public:
	virtual void ShowMenu(char menu) = 0;

};
