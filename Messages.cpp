#include <iostream>
#include "ConsoleInput.h"
#include "ConsoleUI.h"
#include "AccountManager.h"
#include <string>
#include <format>


int main()
{
	//UI System. Interchangable by changing the class type in make_unique.
	std::unique_ptr<BaseUI> uiSystem = std::make_unique<ConsoleUI>();

	//Input system. Interchangable by changing the class type in make_unique.
	//Here because different UI systems might require a custom input system too.
	std::unique_ptr<BaseInput> inputSystem = std::make_unique<ConsoleInput>();

	std::unique_ptr<AccountManager> accountManager = std::make_unique<AccountManager>();

	Account* currentlyLoggedInAccount = nullptr;
	void* customDataPtr = nullptr;

	EMenus currentMenu = EMenus::MainMenu;
	bool quit = false;

	do
	{
		//Render Menu
		uiSystem->ShowMenu(currentMenu, customDataPtr);

		//Get/Apply input depending on menu
		switch (currentMenu)
		{
		case EMenus::MainMenu:
		{
			char input = tolower(inputSystem->GetChar());

			//Are we quitting the application?
			if (input == 'x')
			{
				quit = true;
				break;
			}

			switch (input)
			{
			case '1':
				currentMenu = EMenus::LogInMenu;
				break;

			case '2':
				currentMenu = EMenus::CreateAccountMenu;
				break;

			case '3':
				currentMenu = EMenus::DeleteAccountMenu;
				break;

			case '4':
				currentMenu = EMenus::ViewAccountsMenu;
				break;
			}

			break;
		}

		case EMenus::LogInMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (currentlyLoggedInAccount = accountManager->GetUserAccount(str))
			{
				currentMenu = EMenus::LoggedInMenu;
				customDataPtr = currentlyLoggedInAccount;
			}
			else
			{
				uiSystem->ShowCustomMessage("Account not found.\n\nInput any key to try again.\t(b) Back to Main menu.\n");

				if (inputSystem->GetSpecifiedChar('b'))
				{
					currentMenu = EMenus::MainMenu;
				}
			}

			break;
		}

		case EMenus::LoggedInMenu:
		{
			switch (tolower(inputSystem->GetChar()))
			{
			case '1':
				currentMenu = EMenus::SendMessageMenu;
				break;

			case '2':
				currentMenu = EMenus::ReadUnreadMessagesMenu;
				break;

			case '3':
				currentMenu = EMenus::ReadArchivedMessagesMenu;
				break;

			case '4':
				currentMenu = EMenus::MainMenu;
				currentlyLoggedInAccount = nullptr;
				customDataPtr = nullptr;
				break;
			}

			break;
		}

		case EMenus::CreateAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (accountManager->CreateUserAccount(str))
			{
				uiSystem->ShowCustomMessage("Account created successfully! Head to Main menu to log in.\n\n(b) Back to Main menu.\n");
			}
			else
			{
				uiSystem->ShowCustomMessage("Error: An account with that name already exists.\n\n(b) Back to Main menu.\n");
			}

			inputSystem->WaitForButtonPress('b', currentMenu, EMenus::MainMenu);
			break;
		}

		case EMenus::DeleteAccountMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (accountManager->DeleteUserAccount(str))
			{
				uiSystem->ShowCustomMessage("Account deleted successfully!\n\n(b) Back to Main menu.\n");
			}
			else
			{
				uiSystem->ShowCustomMessage("Error: An account with that name does not exists.\n\n(b) Back to Main menu.\n");
			}

			inputSystem->WaitForButtonPress('b', currentMenu, EMenus::MainMenu);
			break;
		}

		case EMenus::ViewAccountsMenu:
		{
			std::vector<Account>& allAccounts = accountManager->GetAllUserAccounts();
			for (Account& acc : allAccounts)
			{
				uiSystem->ShowCustomMessage(acc.GetName() + "\n");
			}

			uiSystem->ShowCustomMessage("\n\n(b) Back to Main menu.\n");

			inputSystem->WaitForButtonPress('b', currentMenu, EMenus::MainMenu);
			break;
		}

		case EMenus::SendMessageMenu:
		{
			std::string str;
			inputSystem->GetLine(str);

			if (Account* receiver = accountManager->GetUserAccount(str))
			{
				uiSystem->ShowCustomMessage("Account found! Please enter your message:\n\n");

				inputSystem->GetLine(str);
				receiver->AddNewMessage(str, currentlyLoggedInAccount->GetName());

				uiSystem->ShowCustomMessage("Message successfully sent.\n\n(b) Back to your account.\n");
			}
			else
			{
				uiSystem->ShowCustomMessage("\nError: No account with that name could be found.\t(b) Back to your account.");
			}

			inputSystem->WaitForButtonPress('b', currentMenu, EMenus::LoggedInMenu);
			break;
		}

		case EMenus::ReadUnreadMessagesMenu:
		{
			std::vector<TextMessage>& unreadMessages = currentlyLoggedInAccount->GetUnreadMessages();
			if (unreadMessages.size() == 0)
			{
				uiSystem->ShowCustomMessage("You have 0 unread messages. All caught up!\n\n(b) Back to your account.\n", true);
				inputSystem->WaitForButtonPress('b', currentMenu, EMenus::LoggedInMenu);
				break;
			}

			TextMessage* currentMessage;
			for (size_t i = 0; i < unreadMessages.size();)
			{
				currentMessage = &unreadMessages[i];
				currentMessage->SetHasBeenRead();

				uiSystem->ShowCustomMessage(std::format("Displaying unread message {} of {}.\n\n", i + 1, unreadMessages.size()), true);
				uiSystem->ShowCustomMessage(std::format("From: {}\n", currentMessage->GetSenderName()));
				uiSystem->ShowCustomMessage(currentMessage->GetMessageString());
				uiSystem->ShowCustomMessage("\n\n(p) Read previous message.\t(n) Read next message.\t(r) Reply to message.\t(b) Back to your account.\n");

				switch (tolower(inputSystem->GetChar()))
				{
				case 'p':
					if (i > 0)
					{
						--i;
					}
					break;

				case 'n':
					if (i < unreadMessages.size() - 1)
					{
						++i;
					}
					break;

				case 'r':
				{
					if (Account* sender = accountManager->GetUserAccount(currentMessage->GetSenderName()))
					{
						uiSystem->ShowCustomMessage("Please enter your reply: ");
						
						std::string str;
						inputSystem->GetLine(str);

						sender->AddNewMessage(str, currentlyLoggedInAccount->GetName());
						uiSystem->ShowCustomMessage("\nMessage sent. Enter any key to continue.\n");
						inputSystem->GetChar();
					}
					else
					{
						uiSystem->ShowCustomMessage(std::format("Account with name '{}' does not exist. Enter any key to continue.\n", currentMessage->GetSenderName()));
						inputSystem->GetChar();
					}
					break;
				}

				case 'b':
					i = unreadMessages.size();
					currentMenu = EMenus::LoggedInMenu;
					break;
				}

			}

			currentlyLoggedInAccount->ArchiveReadMessages();
			break;
		}

		case EMenus::ReadArchivedMessagesMenu:
		{
			std::vector<TextMessage>& archivedMessages = currentlyLoggedInAccount->GetArchivedMessages();
			if (archivedMessages.size() == 0)
			{
				uiSystem->ShowCustomMessage("You have 0 archived messages.\n\n(b) Back to your account.\n", true);
				inputSystem->WaitForButtonPress('b', currentMenu, EMenus::LoggedInMenu);
				break;
			}

			TextMessage* currentMessage;
			for (size_t i = 0; i < archivedMessages.size();)
			{
				currentMessage = &archivedMessages[i];

				uiSystem->ShowCustomMessage(std::format("Displaying archived message {} of {}.\n\n", i + 1, archivedMessages.size()), true);
				uiSystem->ShowCustomMessage(std::format("From: {}\n", currentMessage->GetSenderName()));
				uiSystem->ShowCustomMessage(currentMessage->GetMessageString());
				uiSystem->ShowCustomMessage("\n\n(p) Read previous message.\t(n) Read next message.\t(r) Reply to message.\t(b) Back to your account.\n");

				switch (tolower(inputSystem->GetChar()))
				{
				case 'p':
					if (i > 0)
					{
						--i;
					}
					break;

				case 'n':
					if (i < archivedMessages.size() - 1)
					{
						++i;
					}
					break;

				case 'r':
				{
					if (Account* sender = accountManager->GetUserAccount(currentMessage->GetSenderName()))
					{
						uiSystem->ShowCustomMessage("Please enter your reply: ");

						std::string str;
						inputSystem->GetLine(str);

						sender->AddNewMessage(str, currentlyLoggedInAccount->GetName());
						uiSystem->ShowCustomMessage("\nMessage sent. Enter any key to continue.\n");
						inputSystem->GetChar();
					}
					else
					{
						uiSystem->ShowCustomMessage(std::format("Account with name '{}' does not exist. Enter any key to continue.\n", currentMessage->GetSenderName()));
						inputSystem->GetChar();
					}
					break;
				}

				case 'b':
					i = archivedMessages.size();
					currentMenu = EMenus::LoggedInMenu;
					break;
				}

			}
			break;
		}

		}

	} while (quit == false);

}
