#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsUser.h"
#include "clsLogs.h"

class clsPermissionsListScreen : protected clsScreen
{
private:

    static string SelectPermissionName(clsUser::enPermissions Permission)
    {
        switch (Permission)
        {
        case clsUser::epAll:
            return "Admin";

        case clsUser::epListClient:
            return "List Clients ";

        case clsUser::epAddClient:
            return "Add Client   ";

        case clsUser::epDeleteClient:
            return "Delete Client";

        case clsUser::epUpdateClient:
            return "Update Client";

        case clsUser::epFindClient:
            return "Find Client  ";

        case clsUser::epTransacion:
            return "Transactions ";

        case clsUser::epManageUsers:
            return "Manage Users ";

        default:
            return "Unknown Permission";
        }
    }

    static string GetUserPermissions(clsUser User)
    {
        // Admin case
        if (User.Permissions == clsUser::epAll)
            return SelectPermissionName(clsUser::epAll);

        clsUser::enPermissions arrPermissions[] =
        {
            clsUser::epListClient,
            clsUser::epAddClient,
            clsUser::epDeleteClient,
            clsUser::epUpdateClient,
            clsUser::epFindClient,
            clsUser::epTransacion,
            clsUser::epManageUsers
        };

        string Permissions = "";
        bool First = true; // عشان نتأكد اننا ما نحط سيبراتور في الاول

        for (clsUser::enPermissions p : arrPermissions)
        {
            if (User.CheckAccessPermission(p))
            {
                if (!First)
                    Permissions += " | ";

                Permissions += SelectPermissionName(p);
                First = false;
            }
        }

        if (Permissions.empty())
            return clsUtility::ColorText(clsUtility::enRED, "No Permissions                                                                                     "); 
        //كل المسافات ديه عشان ديه حاله خاص متلونه احمر فا ال 
        // setw
        // مع الاوان مش بيظبط

        return Permissions;
    }

    static void PrintUserPermissionRecordLine(clsUser User)
    {
        cout << clsUtility::ColorText(clsUtility::enRED, "| ")
            << left << setw(15) << User.UserName
            << clsUtility::ColorText(clsUtility::enRED, "| ")
            << left << setw(99) << GetUserPermissions(User)
            << clsUtility::ColorText(clsUtility::enRED, " |");
    }

public:

    static void ShowPermissionsListScreen()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();
        clsLogs Log(clsLogs::enListPermissions);

        system("cls");

        string Title = "\n\t\t\t\t\t\tUsers Permissions List Screen";
        string SubTitle =
            clsUtility::ColorTextBlock(clsUtility::enYELLOW, clsUtility::enRED,
                "(", to_string(vUsers.size()), ")", " User(s)\n");

        _DrawScreenHeader(Title, SubTitle,
            clsUtility::enRED, clsUtility::enYELLOW);

        cout << endl
            << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

        cout << clsUtility::ColorText(clsUtility::enRED, "| ")
            << left << setw(15) << "User Name"
            << clsUtility::ColorText(clsUtility::enRED, "| ")
            << left << setw(99) << "Permissions"
            << clsUtility::ColorText(clsUtility::enRED, " |") << endl;

        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

        if (vUsers.empty())
        {
            cout << "\n\t\t\t\t\t\tNo Users Available In The System!!";
        }
        else
        {
            for (clsUser& U : vUsers)
            {
                PrintUserPermissionRecordLine(U);
                cout << endl;
            }
        }
        cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;
    }
};
