#pragma once
#include <iostream>
#include <vector>
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsLogs.h"

class clsRefreshUsersScreen : clsScreen
{


public:

	static void RefreshUsers()
	{
		system("cls");

		clsUser::Refresh();
		clsLogs Log(clsLogs::enRefreshUsers);

		system("cls");
		string Title = "\n\t\t\t\t\t\tUsers Refresh Screen";
		_DrawScreenHeader(Title);
		cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

		cout << clsUtility::ColorText(clsUtility::enGREEN, "\t\t\t\t\t  Users have been refreshed successfully" )<< endl;


	}



};

