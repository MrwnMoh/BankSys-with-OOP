#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsSystemLogsScreen.h"
#include "clsTransferLogsScreen.h"

class clsLogsMenu : protected clsScreen
{

	enum enLogsOptions {
		eSystemLogs = 1, eTransferLogs = 2, eManageUsers = 3,};

	static short _ReadLogsOption()
	{
		cout << "Choose what do you want " << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1,3", "] : ");
		short Choice = clsInputValidation::ReadNumberBetween<short>(1, 3);
		return Choice;
	}

	static void _ShowSystemLogs()
	{
		clsSystemLogsScreen::ShowLogsScreen();
	}

	static void _ShowTransferLogs()
	{
		clsTransferLogsScreen::ShowLogsScreen();
	}

	static  void _GoBackToManageUsersMenue()
	{
		cout << "\nPress any key to go back to Logs Menue...\n";
		system("pause>0");
		ShowLogsMenu();
	}


    static void _PereformMianMenuOptions(enLogsOptions eLogs)
    {
        switch (eLogs)
        {
        case clsLogsMenu::eSystemLogs:
			_ShowSystemLogs();
            break;
        case clsLogsMenu::eTransferLogs:
			_ShowTransferLogs();
            break;
        default:
            break;
        }
        if (eLogs != eManageUsers)
            _GoBackToManageUsersMenue();
    }


public :

	static void ShowLogsMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tLogs Menu Screen");

		cout << "\n\n";
		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");
		cout << setw(37) << left << "" << "\t\t\tLogs Menue\n";
		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1", "]");
		cout << " System Logs.\n";

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "2", "]");
		cout << " Transfer Logs.\n";

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "3", "]");
		cout << " Manage Users Screen.\n";
		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|") << endl;

		_PereformMianMenuOptions((enLogsOptions)_ReadLogsOption());

	}




};

