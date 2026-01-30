#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include "clsLogs.h"

class clsTotalBalancesScreen : protected clsScreen
{

    static string _TotalBalanceLine(double TotalBalances)
        {
            return clsUtility::ColorText(clsUtility::enRED, "| ")
                + "Total Balances = " +
                clsUtility::ColorText(clsUtility::enGREEN, "$ ") +
                to_string(TotalBalances) +
                clsUtility::ColorText(clsUtility::enRED, " ( ") +
                clsUtility::NumberToText(TotalBalances) +
                clsUtility::ColorText(clsUtility::enRED, " )");
        }

    static void _PrintClientRecordeBalanceLine(clsBankClient Client)
        {
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << Client.AccountNumber;
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(50) << Client.FullName();
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << clsUtility::ColorText(clsUtility::enGREEN, "$ ") << left << setw(45) << to_string(Client.AccountBalance);
            cout << clsUtility::ColorText(clsUtility::enRED, " |");
        }

public:

    static void ShowTotalBalances()
    {
        system("cls");
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        clsLogs Log(clsLogs::enTotalBalances);
        string Title = "\n\t\t\t\t\t\tBalances List Screen";
        string SubTitle = clsUtility::ColorTextBlock(clsUtility::enYELLOW, clsUtility::enRED, "(", to_string(vClients.size()), ")", "client(s).\n");
        _DrawScreenHeader(Title, SubTitle, clsUtility::enRED, clsUtility::enYELLOW);
        cout << "\n\n" << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;



        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << "Account Number";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(50) << "Client Name";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(47) << "Balance";
        cout << clsUtility::ColorText(clsUtility::enRED, " |") << endl;
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
        {
            cout << "\n\t\t\t\t\t\tNo Clients Abailabe In the System!!";
        }
        else
        {
            for (clsBankClient& Client : vClients)
            {
                _PrintClientRecordeBalanceLine(Client);
                cout << endl;

            }
        }
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;
        
        cout << left << setw(154) << _TotalBalanceLine(TotalBalances) << clsUtility::ColorText(clsUtility::enRED," |");
        
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

    }

    


};

