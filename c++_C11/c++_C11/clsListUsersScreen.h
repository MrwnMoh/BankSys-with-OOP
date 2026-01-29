





#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsLogs.h"

class clsListUsersScreen : protected clsScreen
{

    static void PrintUserRecordeLine(clsUser User)
    {
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << User.UserName;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << User.FullName();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(12) << User.Phone;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << User.Email;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(10) << User.Password;
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << clsUtility::ColorText(clsUtility::enBLUE, "* ") << left << setw(17) << User.Permissions;
        cout << clsUtility::ColorText(clsUtility::enRED, " |");
    }
public:

    static void ShowUsersList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();
        clsLogs Log(clsLogs::enListUsers);
        system("cls");
        string Title = "\n\t\t\t\t\t\tUsers List Screen";
        string SubTitle = clsUtility::ColorTextBlock(clsUtility::enYELLOW, clsUtility::enRED, "(", to_string(vUsers.size()), ")", "User(s).\n");
        _DrawScreenHeader(Title, SubTitle, clsUtility::enRED, clsUtility::enYELLOW);
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(15) << "User Name";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << "Full Name";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(12) << "Phone";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(25) << "Email";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(10) << "Password";
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(19) << "Permissions";
        cout << clsUtility::ColorText(clsUtility::enRED, " |") << endl;
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


        if (vUsers.size() == 0)
        {
            cout << "\n\t\t\t\t\t\tNo Users Abailabe In the System!!";
        }
        else
        {
            for (clsUser& U : vUsers)
            {
                PrintUserRecordeLine(U);
                cout << endl;

            }
        }
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


    }








};

