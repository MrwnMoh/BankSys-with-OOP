#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsLogs.h"

class clsWithdrawScreen : protected clsScreen
{
    static double ReadAmount()
    {
        cout << "Please enter Wihdraw amount : ";
        double Amount = clsInputValidation::clsInputValidation::ReadNumber<double>();
        while (Amount <= 0)
        {
            cout << clsUtility::ColorText(clsUtility::enRED, "Withdraw amount must be greater than zero. Please try again: ");
            Amount = clsInputValidation::clsInputValidation::ReadNumber<double>();
        }
        return Amount;
    }

public :

    static void ShowWithdrawScreen()
    {
        char WithdrawAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tWithdraw Screen";
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
            
            double Amount = ReadAmount();


            char Answer = clsInputValidation::ReadChar("Are you sure you want to withdraw this client [y/n] : ");
            if (toupper(Answer) == 'Y')
            {
                Client.Withdraw(Amount);
                cout << clsUtility::ColorText(clsUtility::enGREEN, "\nAmount Withdrawed Successfully.\n");
                cout << "New Balance Is : " << clsUtility::ColorText(clsUtility::enGREEN, "$ ") << to_string(Client.AccountBalance);
                clsLogs Log(clsLogs::enWithdraw);
            }
            else
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nOperation was canselled..\n");
            }
            WithdrawAgainMessage = clsInputValidation::ReadChar("\nDo you want to withdraw another client? (Y/N) Or try again : ");
        } while (toupper(WithdrawAgainMessage) == 'Y');


    }




};

