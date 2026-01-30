#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClinetScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLogs.h"
#include "clsCurrencyExhangeScreen.h"

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eCurrencyExhange = 8 , eExit = 9
    };

    static short _ReadMianMenuOption()
    {
        

        cout << "Choose what do you want " << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1,9", "] : ");
        short Choice = clsInputValidation::ReadNumberBetween<short>(1, 9);
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout <<"\nPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainScreenMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClient::ShowAddNewClient();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClinetScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsScreen();

    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowCurrencyExhangeMenue()
    {
        clsCurrencyExhangeScreen::ShowCurrencyExhangeMenue();
    }


    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static string CanAccsesToOption(enMainMenuOptions eOption)
    {
        switch (eOption)
        {
        case clsMainScreen::eListClients:           return CurrentUser.CheckAccessPermission(CurrentUser.epListClient)       ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eAddNewClient:          return CurrentUser.CheckAccessPermission(CurrentUser.epAddClient)        ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eDeleteClient:          return CurrentUser.CheckAccessPermission(CurrentUser.epDeleteClient)     ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eUpdateClient:          return CurrentUser.CheckAccessPermission(CurrentUser.epUpdateClient)     ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eFindClient:            return CurrentUser.CheckAccessPermission(CurrentUser.epFindClient)       ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eShowTransactionsMenue: return CurrentUser.CheckAccessPermission(CurrentUser.epTransacion)       ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eManageUsers:           return CurrentUser.CheckAccessPermission(CurrentUser.epManageUsers)      ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eCurrencyExhange:       return CurrentUser.CheckAccessPermission(CurrentUser.epCurrencyExhange)  ?  clsUtility::ColorText(clsUtility::enGREEN, ">") : clsUtility::ColorText(clsUtility::enRED, ">");
        case clsMainScreen::eExit:                  return clsUtility::ColorText(clsUtility::enGREEN, ">");
        default:
            break;
        }

    }

    static void _PereformMianMenuOptions(enMainMenuOptions eMainMenu)
    {
        switch (eMainMenu)
        {
        case enMainMenuOptions::eListClients:
        {
            _ShowAllClientsScreen();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
            _ShowAddNewClientsScreen();
            break;

        case enMainMenuOptions::eDeleteClient:
            _ShowDeleteClientScreen();
            break;

        case enMainMenuOptions::eUpdateClient:
            _ShowUpdateClientScreen();
            break;

        case enMainMenuOptions::eFindClient:
            _ShowFindClientScreen();
            break;

        case enMainMenuOptions::eShowTransactionsMenue:
            _ShowTransactionsMenue();
            break;

        case enMainMenuOptions::eManageUsers:
            _ShowManageUsersMenue();
            break;
        case enMainMenuOptions::eCurrencyExhange:
            _ShowCurrencyExhangeMenue();
            break;
        case enMainMenuOptions::eExit:
            clsLogs Log(clsLogs::enLogout);

            ;
            _Logout();
            break;
        }
        if(eMainMenu != eExit)
        _GoBackToMainMenue();

    }

public:


	static void ShowMainScreenMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

        cout << "\n\n";
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");


        cout << CanAccsesToOption(eListClients);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1", "]");
        cout << " Show Client List.\n";

        cout << CanAccsesToOption(eAddNewClient);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "2", "]");
        cout << " Add New Client.\n";

        cout << CanAccsesToOption(eDeleteClient);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "3", "]");
        cout << " Delete Client.\n";

        cout << CanAccsesToOption(eUpdateClient);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "4", "]");
        cout << " Update Client Info.\n";

        cout << CanAccsesToOption(eFindClient);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "5", "]");
        cout << " Find Client.\n";

        cout << CanAccsesToOption(eShowTransactionsMenue);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "6", "]");
        cout << " Transactions.\n";

        cout << CanAccsesToOption(eManageUsers);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "7", "]");
        cout << " Manage Users.\n";

        cout << CanAccsesToOption(eCurrencyExhange);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "8", "]");
        cout << " Currency Exhange.\n";

        cout << CanAccsesToOption(eExit);
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "9", "]");
        cout << " Logout.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|") << endl;


        _PereformMianMenuOptions(enMainMenuOptions(_ReadMianMenuOption()));

	}




};

