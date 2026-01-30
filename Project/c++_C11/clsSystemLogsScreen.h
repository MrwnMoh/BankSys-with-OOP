#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsLogs.h"


class clsSystemLogsScreen : protected clsScreen
{

    static string StatusColored(string Status)
    {


        //Login\logout
        if (Status == "Login")
            return clsUtility::ColorText(clsUtility::enGREEN, Status + "                         ");
        else if(Status == "Logout")
            return clsUtility::ColorText(clsUtility::enRED, Status + "                        ");

        //Logs
        else if(Status == "System Logs Loaded")
            return clsUtility::ColorText(clsUtility::enYELLOW, Status + "            ");
        else if (Status == "Transfer Logs Loaded")
            return clsUtility::ColorText(clsUtility::enYELLOW, Status + "          ");

        //User
        else if(Status == "Updated User")
            return clsUtility::ColorText(clsUtility::enMAGENTA, Status + "                  ");
        else if(Status == "Added User")
            return clsUtility::ColorText(clsUtility::enMAGENTA, Status + "                    ");
        else if (Status == "Found User")
            return clsUtility::ColorText(clsUtility::enMAGENTA, Status + "                    ");
        else if(Status == "Deleted User")
            return clsUtility::ColorText(clsUtility::enMAGENTA, Status + "                  ");
        else if (Status == "Show Users List")
            return clsUtility::ColorText(clsUtility::enMAGENTA, Status + "               ");
        else if (Status == "Show Permissions List")
            return clsUtility::ColorText(clsUtility::enMAGENTA, Status + "         ");
        else if (Status == "Refresh Users")
            return clsUtility::ColorText(clsUtility::enMAGENTA, Status + "                 ");

        //client
        else if (Status == "Updated Client")
            return clsUtility::ColorText(clsUtility::enBLUE, Status + "                ");
        else if (Status == "Added Client")
            return clsUtility::ColorText(clsUtility::enBLUE, Status + "                  ");
        else if (Status == "Found Client")
            return clsUtility::ColorText(clsUtility::enBLUE, Status + "                  ");
        else if (Status == "Deleted Client")
            return clsUtility::ColorText(clsUtility::enBLUE, Status + "                ");
        else if (Status == "Show Clients List")
            return clsUtility::ColorText(clsUtility::enBLUE, Status + "             ");

        //Currencies
        else if (Status == "Currency rate updated")
            return clsUtility::ColorText(clsUtility::enCYAN, Status + "         ");
        else if (Status == "Found Currencis")
            return clsUtility::ColorText(clsUtility::enCYAN, Status + "               ");
        else if (Status == "Show Currencis List")
            return clsUtility::ColorText(clsUtility::enCYAN, Status + "           ");
        else if (Status == "Currency Calc")
            return clsUtility::ColorText(clsUtility::enCYAN, Status + "                 ");

        //Transacions
        else if (Status == "Show Total Balances")
            return clsUtility::ColorText(clsUtility::enYELLOW, Status + "           ");
        else if (Status == "Transfer")
            return clsUtility::ColorText(clsUtility::enYELLOW, Status + "                      ");
        else if (Status == "Withdraw")
            return clsUtility::ColorText(clsUtility::enYELLOW, Status + "                      ");
        else if (Status == "Deposit")
            return clsUtility::ColorText(clsUtility::enYELLOW, Status + "                       ");

        return "Unknown";
    }

    static void PrintLogRecordeLine(clsLogs Log)
    {
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << Log.UserName();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(30) << StatusColored(Log.Status());
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(30) << Log.Timestamp();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << Log.Password();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << clsUtility::ColorText(clsUtility::enBLUE, "* ") << left << setw(16) << Log.Permission();
        cout << clsUtility::ColorText(clsUtility::enRED, " |");
    }

    static bool CheckPermissions()
    {
      return  CurrentUser.Permissions == -1 ? true : false;
    }
    
    static string SubTilte2()
    {
        string Users = clsUtility::ColorTextBlock(clsUtility::enWHITE, clsUtility::enMAGENTA, "(","*", ")");
        string Clients = clsUtility::ColorTextBlock(clsUtility::enWHITE, clsUtility::enBLUE, "(","*", ")");
        string Currencis = clsUtility::ColorTextBlock(clsUtility::enWHITE, clsUtility::enCYAN, "(","*", ")");
        string Logs_Transactions = clsUtility::ColorTextBlock(clsUtility::enWHITE, clsUtility::enYELLOW, "(","*", ")");
        string Login = clsUtility::ColorTextBlock(clsUtility::enWHITE, clsUtility::enGREEN, "(","*", ")");
        string Logout = clsUtility::ColorTextBlock(clsUtility::enWHITE, clsUtility::enRED, "(","*", ")");

        string Sub = "\t\t  Users " + Users + " Clients " + Clients + " Currencis " + Currencis + " Logs/Transactions " + Logs_Transactions + " Login " + Login + " Logout " + Logout;
        return Sub;
    }

public:

    static void ShowLogsScreen()
    {
        if (CheckPermissions())
        {
            clsLogs Log(clsLogs::enSystemLogsLoaded);
            vector <clsLogs> vLogs = clsLogs::GetSystemLogsList();
            system("cls");
            string Title = "\n\t\t\t\t\t\tSystem Logs List Screen";
            string Sub2 = SubTilte2();
            string SubTitle = clsUtility::ColorTextBlock(clsUtility::enYELLOW, clsUtility::enRED, "    (", to_string(vLogs.size()), ")", "Log(s).\n" + Sub2);

            _DrawScreenHeader(Title, SubTitle, clsUtility::enRED, clsUtility::enYELLOW);
            cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << "User Name";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(30) << "Status";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(30) << "Timestamp";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << "Password";
            cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(18) << "Permissions";
            cout << clsUtility::ColorText(clsUtility::enRED, " |") << endl;
            cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


            if (vLogs.size() == 0)
            {
                cout << "\n\t\t\t\t\t\tNo Logs_Transactions Abailabe In the System!!";
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

