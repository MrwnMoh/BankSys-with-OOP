#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsUtility.h"
#include "clsInputValidation.h"
#include "clsLogs.h"

using namespace std;

class clsTransfareScreen : protected clsScreen
{


    static string _GetAccountNumber(string Massege)
    {
        cout << Massege;
        string AccountNumber;
        AccountNumber = clsInputValidation::ReadString();
        while (!clsBankClient::IsUserExist(AccountNumber))
        {
            cout << clsUtility::ColorText(clsUtility::enRED, "\nAccount number is not found, choose another one : ");
            AccountNumber = clsInputValidation::ReadString();
        }

        return AccountNumber;
    }

    static bool _CheckIsAccountsNumberIsSame(string Acc1,string Acc2)
    {
        return Acc1 == Acc2;
    }

    static double _ReadAmount()
    {
        cout << "Please enter transfare amount : ";
        double Amount = clsInputValidation::clsInputValidation::ReadNumber<double>();
        while (Amount <= 0)
        {
            cout << clsUtility::ColorText(clsUtility::enRED, "Transfer amount must be greater than zero. Please try again: ");
            Amount = clsInputValidation::clsInputValidation::ReadNumber<double>();
        }
        return Amount;
    }

    static bool _CheckTransfareAmount(double Balance,double Amount)
    {
        return Amount > Balance;
    }

    
public:

    static void ShowTransfareScreen()
    {
        char UpdateAgainMessage = 'n';
        do
        {
            system("cls");

            string Tilte = "\tTransfare Screen";
            _DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

            clsBankClient SourceClient = clsBankClient::Find(_GetAccountNumber("\nPLease enter client Account Number To Transfer from : "));
            clsScreen::_PrintClientSummary(SourceClient);

            string DistinationClientAccountNumber = _GetAccountNumber("\nPLease enter client Account Number To Transfer To : ");

            while (_CheckIsAccountsNumberIsSame(SourceClient.AccountNumber, DistinationClientAccountNumber))
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nError: You cannot transfer to the same account.Please select a different account.");
                string DistinationClientAccountNumber = _GetAccountNumber("\nPLease enter client Account Number To Transfer To : ");

            } 
            clsBankClient DistinationClient = clsBankClient::Find(DistinationClientAccountNumber);
            clsScreen::_PrintClientSummary(DistinationClient);

            double TransferAmount = _ReadAmount();
            while (_CheckTransfareAmount(SourceClient.AccountBalance, TransferAmount))
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nAmount Exceeds the available balance, Enter anouther amount!");
                double TransfareAmount = _ReadAmount();
            }

            char Answer = clsInputValidation::ReadChar("Are you sure you want to Perform this operation [y/n] : ");
            if (toupper(Answer) == 'Y')
            {
                SourceClient.Transfer(TransferAmount, DistinationClient);
                cout << clsUtility::ColorText(clsUtility::enGREEN, "\nTransfer Done Successfully.\n");
                _PrintClientSummary(SourceClient);
                _PrintClientSummary(DistinationClient);
                clsLogs sLog(clsLogs::enTransfer);
                clsLogs Log(clsLogs::enTransfer,SourceClient.AccountNumber,DistinationClient.AccountNumber, SourceClient.AccountBalance, DistinationClient.AccountBalance, TransferAmount);
            }
            else
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nOperation was canselled..\n");
            }

            UpdateAgainMessage = clsInputValidation::ReadChar("Do you want to perform another transfer? (Y/N):");
        } while (toupper(UpdateAgainMessage) == 'Y');



    }

};

