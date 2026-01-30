#pragma once
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"


class clsFindeUserScreen : clsScreen
{




public:
    static void ShowFindUserScreen()
    {
        char FindAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tFind User Screen";
            _DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

            string UserName = "";
            cout << "\nPLease enter UserName : ";
            UserName = clsInputValidation::ReadString();
            while (!clsUser::IsUserExist(UserName))
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nUserName is not found, choose another one : ");
                UserName = clsInputValidation::ReadString();
            }

            clsUser User = clsUser::Find(UserName);

            if (User.IsEmpty())
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nUser Not Founded !!\n");
            }
            else
            {
                cout << clsUtility::ColorText(clsUtility::enGREEN, "\nUser Founded Successfully..\n");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                clsLogs Log(clsLogs::enFoundUser);
                clsScreen::_Print(User);
            }

            FindAgainMessage = clsInputValidation::ReadChar("Do you want to Find another User? (Y/N) : ");
        } while (toupper(FindAgainMessage) == 'Y');
    }


};

