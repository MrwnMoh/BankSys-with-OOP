#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsLogs.h"


class clsDepositScreen : protected clsScreen
{

    static double ReadAmount()
    {
        cout << "Please enter diposit amount : ";
        double Amount = clsInputValidation::ReadNumber<double>();
        while (Amount <= 0)
        {
            cout << clsUtility::ColorText(clsUtility::enRED, "Deposit amount must be greater than zero. Please try again: ");
                Amount = clsInputValidation::clsInputValidation::ReadNumber<double>();
        }
        return Amount;
    }

public:

	static void ShowDepositScreen()
	{
        char DepositAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tDeposit Screen";
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

            char Answer = clsInputValidation::ReadChar("Are you sure you want to deposit this client [y/n] : ");
            if (toupper(Answer) == 'Y')
            {
                Client.Deposit(Amount);
                cout << clsUtility::ColorText(clsUtility::enGREEN, "\nAmount Deposited Successfully.\n");
                cout << "New Balance Is : " << clsUtility::ColorText(clsUtility::enGREEN, "$ ") << to_string(Client.AccountBalance);
                clsLogs Log(clsLogs::enDeposit);
            }
            else
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nOperation was canselled..\n");
            }
            DepositAgainMessage = clsInputValidation::ReadChar("\nDo you want to deposit another client? (Y/N) Or try again : ");
        } while (toupper(DepositAgainMessage) == 'Y');


	}

	
};

