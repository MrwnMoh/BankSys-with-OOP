#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsLogs.h"

class clsDeleteClientScreen : protected clsScreen
{

public:
    
	static void ShowDeleteClientScreen()
    {
        if (!_CheckAccessRightes(clsUser::enPermissions::epDeleteClient))
            return;

        char DeleteAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tDelete Client Screen";
            _DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

            string AccountNumber = "";
            cout << "\nPLease enter client Account Number : ";
            AccountNumber = clsInputValidation::ReadString();
            while (!clsBankClient::IsUserExist(AccountNumber))
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nAccount number is not found, choose another one : ");
                AccountNumber = clsInputValidation::ReadString();
            }

            clsBankClient Client = clsBankClient::Find(AccountNumber);
            clsScreen::_Print(Client);

            char Answer = clsInputValidation::ReadChar("Are you sure you want to delete this client [y/n] : ");
            if (toupper(Answer) == 'Y')
            {
                clsBankClient::enSaveResults SaveResult;
                SaveResult = Client.Delete();
                switch (SaveResult)
                {
                case  clsBankClient::enSaveResults::svSucceeded:
                {
                    cout << clsUtility::ColorText(clsUtility::enGREEN, "\nAccount Deleted Successfully :-)\n");
                    cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                    clsLogs Log(clsLogs::enDeletedClient);

                    clsScreen::_Print(Client);
                    break;
                }
                case clsBankClient::enSaveResults::svFaildDeleted:
                {
                    cout << clsUtility::ColorText(clsUtility::enRED, "\nError account was not Deleted");
                    break;

                }

                }
            }
            else
                cout << clsUtility::ColorText(clsUtility::enRED, "\nDelete has been canceled");


            DeleteAgainMessage = clsInputValidation::ReadChar("\nDo you want to delete another client? (Y/N) Or try again : ");
        } while (toupper(DeleteAgainMessage) == 'Y');
    }





};

