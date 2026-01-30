#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsLogs.h"

class clsTransferLogsScreen : protected clsScreen
{
    static void PrintLogRecordeLine(clsLogs Log)
    {
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(12) << Log.UserName();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(23) << Log.Timestamp();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(9) << Log.SuorseCL();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(9) << Log.DestinaionCL();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(17) << Log.TransferAmount();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(17) << Log.SuorseClBlncAfTrns();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(17) << Log.DesinationClBlncAfTrns();
        cout << clsUtility::ColorText(clsUtility::enRED, " |");
    }

    static bool CheckPermissions()
    {
        return  CurrentUser.Permissions == -1 ? true : false;
    }

public:

    static void ShowLogsScreen()
    {
        if (CheckPermissions())
        {
            clsLogs Log(clsLogs::enTransferLogsLoaded);
            vector <clsLogs> vLogs = clsLogs::GetTransferLogsList();
            system("cls");
            string Title = "\n\t\t\t\t\t\tTransfer Logs List Screen";
            _DrawScreenHeader(Title);
            cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(12) << "User Name";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(23) << "Timestamp";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(9) << "s.Acct";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(9) << "d.Acct";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(17) << "Amount";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(17) << "s.Balance";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(17) << "d.Balance";
            cout << clsUtility::ColorText(clsUtility::enRED, " |") << endl;
            cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


            if (vLogs.size() == 0)
            {
                cout << "\n\t\t\t\t\t\tNo Logs Abailabe In the System!!";
            }
            else
            {
                for (clsLogs& L : vLogs)
                {
                    PrintLogRecordeLine(L);
                    cout << endl;

                }
            }
            cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

        }
        else
        {
            system("cls");
            _DrawScreenHeader("Restricted Access! Only Admin users can proceed.");
        }



    }





};

