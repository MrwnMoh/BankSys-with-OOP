#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsLogs.h"


class clsUpdateClientScreen : protected clsScreen
{
 
public:

	static void ShowUpdateClientScreen()
    {
        if (!_CheckAccessRightes(clsUser::enPermissions::epUpdateClient))
            return;

        char UpdateAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tUpdate Client Screen";
            _DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

            string AccountNumber = "";
            cout << "\nPLease enter client Account Number : ";
            AccountNumber = clsInputValidation::ReadString();
            while (!clsBankClient::IsUserExist(AccountNumber))
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nAccount number is not found, choose another one : ");
                AccountNumber = clsInputValidation::ReadString();
            }

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            clsScreen::_Print(Client1);
            char Answer = clsInputValidation::ReadChar("Are you sure you want to Update this client [y/n] : ");
            if (toupper(Answer) == 'Y')
            {
                cout << "\n\nUpdate Client Info:";
                cout << "\n_____________________\n";
                clsScreen::_ReadClientInfo(Client1);

                clsBankClient::enSaveResults SaveResult;

                SaveResult = Client1.Save();

                switch (SaveResult)
                {
                case clsBankClient::enSaveResults::svSucceeded:
                {
                    cout << clsUtility::ColorText(clsUtility::enGREEN, "\nAccount Updated Successfully..\n");
                    cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                    clsLogs Log(clsLogs::enUpdatedClient);
                    clsScreen::_Print(Client1);
                    break;
                }
                case clsBankClient::enSaveResults::svFaildEmptyObject:
                {
                    cout << clsUtility::ColorText(clsUtility::enRED, "\nError: User was not Updated! Admin password is required.");
                    break;
                }
                }
            }
            UpdateAgainMessage = clsInputValidation::ReadChar("Do you want to update another client? (Y/N) : ");
        }while (toupper(UpdateAgainMessage) == 'Y');

    }





};

