#pragma once
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"
class clsFindClinetScreen : clsScreen
{


public:
	static void ShowFindClientScreen()
	{
        if (!_CheckAccessRightes(clsUser::enPermissions::epFindClient))
            return;

		char FindAgainMessage = 'n';
		do
		{
            system("cls");
            string Tilte = "\tFind Client Screen";
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

            if (Client.IsEmpty())
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nAccount Not Founded !!\n");
            }
            else
            {
                cout << clsUtility::ColorText(clsUtility::enGREEN, "\nAccount Founded Successfully..\n");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                clsLogs Log(clsLogs::enFoundClient);
                clsScreen::_Print(Client);
            }
            
			FindAgainMessage = clsInputValidation::ReadChar("Do you want to Find another client? (Y/N) : ");
		}while (toupper(FindAgainMessage) == 'Y');
	}

};

