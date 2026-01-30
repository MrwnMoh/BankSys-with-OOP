#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsInputValidation.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsLogs.h"
class clsLoginScreen : protected clsScreen
{

	static bool _Login()

	{
		string UserName, Password;
		short FaildLoginCount = 3;
		while (FaildLoginCount > 0)
		{

			cout << "\nEnter UserName : ";
			UserName = clsInputValidation::ReadString();
			cout << "Enter Password: ";
			Password = clsInputValidation::ReadString();
			
			CurrentUser = clsUser::Find(UserName, Password);
			if (!CurrentUser.IsEmpty())
				break;

			FaildLoginCount--;
			cout << clsUtility::ColorText(clsUtility::enRED, "Invalid UserName/Password!\n");
			cout << clsUtility::ColorText(clsUtility::enRED, "You have " + to_string(FaildLoginCount) + " Trials to login.\n");
			cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|") << "\n\n";
		}
		if(FaildLoginCount != 0)
		{
			clsLogs Log(clsLogs::enLogin);
			clsMainScreen::ShowMainScreenMenu();
			return true;
		}

		cout << clsUtility::ColorText(clsUtility::enRED, "Your are locked after 3 trials. Program will now exit\n");
		exit(0);
		return false;
	}
public:
	
	static void ShowLoginScreen()
	{

		while(true)
		{
			system("cls");
			_DrawScreenHeader("\t\tLogin Screen");
			_Login();
		}

	}



};

