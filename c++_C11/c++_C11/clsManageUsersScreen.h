#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindeUserScreen.h"
#include "clsPermissionsListScreen.h"
#include "clsLogsMenu.h"
#include "clsRefreshUsersScreen.h"

class clsManageUsersScreen : protected clsScreen
{

    enum enManageUsersOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, ePermissionsList = 6 , eLogs = 7, eRefreshUsers =8 , eMainMenue = 9
    };

    static short _ReadManageUsersOption()
    {
        cout << "Choose what do you want " << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1,9", "] : ");
        short Choice = clsInputValidation::ReadNumberBetween<short>(1, 9);
        return Choice;
    }

    static  void _GoBackToManageUsersMenue()
    {
        cout << "\nPress any key to go back to Manage Users Menu...\n";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUser();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindeUserScreen::ShowFindUserScreen();
    }

    static void _ShowLogsMenuScreen()
    {
        clsLogsMenu::ShowLogsMenu();
    }
    
    static void _RefrshUsersScreen()
    {
        clsRefreshUsersScreen::RefreshUsers();
    }

    static void _ShowePermissionsListScreen()
    {
        clsPermissionsListScreen::ShowPermissionsListScreen();
    }

    static void _PereformMianMenuOptions(enManageUsersOptions eManage)
    {
        switch (eManage)
        {
        case clsManageUsersScreen::eListUsers:
            _ShowListUsersScreen();
            break;
        case clsManageUsersScreen::eAddNewUser:
            _ShowAddNewUserScreen();
            break;
        case clsManageUsersScreen::eDeleteUser:
            _ShowDeleteUserScreen();
            break;
        case clsManageUsersScreen::eUpdateUser:
            _ShowUpdateUserScreen();
            break;
        case clsManageUsersScreen::eFindUser:
            _ShowFindUserScreen();
            break;
        case clsManageUsersScreen::ePermissionsList:
            _ShowePermissionsListScreen();
            break;
        case clsManageUsersScreen::eRefreshUsers:
            _RefrshUsersScreen();
            break;
        case clsManageUsersScreen::eLogs:
            _ShowLogsMenuScreen();
            break;
        default:
            break;
        }
        if (eManage != eMainMenue)
            _GoBackToManageUsersMenue();
    }

public:

	static void ShowManageUsersMenue()
	{
        if (!_CheckAccessRightes(clsUser::enPermissions::epManageUsers))
            return;

		system("cls");
		_DrawScreenHeader("\t\tManage Users Screen");

		cout << "\n\n";
		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");
		cout << setw(37) << left << "" << "\t\t\tManage Users Menu\n";
		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1", "]");
        cout << " List Users.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "2", "]");
        cout << " Add New User.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "3", "]");
        cout << " Delete User.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "4", "]");
        cout << " Update User.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "5", "]");
        cout << " Find User.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "6", "]");
        cout << " Permissions List.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "7", "]");
        cout << " Logs.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "8", "]");
        cout << " Refrsh Users.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "9", "]");
        cout << " Main Menue.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|") << endl;

        _PereformMianMenuOptions(enManageUsersOptions(_ReadManageUsersOption()));

	}


};

