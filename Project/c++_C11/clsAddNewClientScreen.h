#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsLogs.h"

class clsAddNewClient : protected clsScreen
{

    static void _ReadClientInfo(clsBankClient& Client)
    {
            cout << "Enter FirstName      : ";
            Client.FirstName = clsInputValidation::ReadString();

            cout << "Enter LastName       : ";
            Client.LastName = clsInputValidation::ReadString();

            cout << "Enter Email          : ";
            Client.Email = clsInputValidation::ReadString();

            cout << "Enter Phone          : ";
            Client.Phone = clsInputValidation::ReadString();

            cout << "Enter PinCode        : ";
            Client.PinCode = clsInputValidation::ReadString();

            cout << "Enter Account Balance: ";
            Client.AccountBalance = clsInputValidation::ReadNumber<float>();
    }

public:

    static void ShowAddNewClient()
    {

        if (!_CheckAccessRightes(clsUser::enPermissions::epAddClient))
            return;

        char AddAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tAdd New Client Screen";
            _DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

            string AccountNumber = "";
            cout << "\nPLease enter client Account Number : ";
            AccountNumber = clsInputValidation::ReadString();
            while (clsBankClient::IsUserExist(AccountNumber))
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nAccount number is Already Used, choose another one : ");
                AccountNumber = clsInputValidation::ReadString();
            }

            clsBankClient NewClient = clsBankClient::GetAddNewUserObject(AccountNumber);

            _ReadClientInfo(NewClient);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = NewClient.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << clsUtility::ColorText(clsUtility::enGREEN, "\nAccount Addeded Successfully :-)\n");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                clsLogs Log(clsLogs::enAddedClient);
                clsScreen::_Print(NewClient);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nError account was not saved because it's Empty");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                break;

            }
            case clsBankClient::enSaveResults::svFalidAccountNumberExist:
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nError account was not saved because account number is used!\n");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                break;
            }

            }
            AddAgainMessage = clsInputValidation::ReadChar("Do you want to add another client? (Y/N) : ");
        }while(toupper(AddAgainMessage) == 'Y');
    }




};

