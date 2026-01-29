#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsBankClient.h"
#include "clsLogs.h"

class clsClientListScreen : protected clsScreen
{
private:

    static void PrintClientRecordeLine(clsBankClient Client)
    {
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << Client.AccountNumber;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << Client.FullName();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(12) << Client.Phone;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << Client.Email;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(10) << Client.PinCode;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << clsUtility::ColorText(clsUtility::enGREEN, "$ ") << left << setw(17) << to_string(Client.AccountBalance);
        cout << clsUtility::ColorText(clsUtility::enRED, " |");
    }
public:

    static void ShowClientsList()
    {
        if (!_CheckAccessRightes(clsUser::enPermissions::epListClient))
            return;

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        clsLogs Log(clsLogs::enListClients);
        system("cls");
        string Title = "\n\t\t\t\t\t\tClients List Screen";
        string SubTitle = clsUtility::ColorTextBlock(clsUtility::enYELLOW,clsUtility::enRED, "(",to_string(vClients.size()), ")", "client(s).\n");
        _DrawScreenHeader(Title, SubTitle,clsUtility::enRED,clsUtility::enYELLOW);
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << "Account Number";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << "Client Name";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(12) << "Phone";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << "Email";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(10) << "Pin Code";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(19) << "Balance";
        cout << clsUtility::ColorText(clsUtility::enRED, " |") << endl;
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


        if (vClients.size() == 0)
        {
            cout << "\n\t\t\t\t\t\tNo Clients Abailabe In the System!!";
        }
        else
        {
            for (clsBankClient& Client : vClients)
            {
                PrintClientRecordeLine(Client);
                cout << endl;

            }
        }
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


    }


};

