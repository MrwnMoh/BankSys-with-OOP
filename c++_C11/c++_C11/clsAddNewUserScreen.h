#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsUser.h"
#include "clsLogs.h"

class clsAddNewUserScreen : protected clsScreen
{
    static void _ReadUserInfo(clsUser& Client)
    {
        cout << "\n\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|") << endl;
        cout << clsUtility::ColorTextBlock(clsUtility::enRED,clsUtility::enYELLOW,"|","> ") << "Enter FirstName      : ";
        Client.FirstName = clsInputValidation::ReadString();
        cout << clsUtility::ColorText(clsUtility::enRED, "|") << endl;

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter LastName       : ";
        Client.LastName = clsInputValidation::ReadString();
        cout << clsUtility::ColorText(clsUtility::enRED, "|") << endl;

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter Email          : ";
        Client.Email = clsInputValidation::ReadString();
        cout << clsUtility::ColorText(clsUtility::enRED, "|") << endl;

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter Phone          : ";
        Client.Phone = clsInputValidation::ReadString();
        cout << clsUtility::ColorText(clsUtility::enRED, "|") << endl;

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter Password       : ";
        Client.Password = clsInputValidation::ReadString();

        cout <<  clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|") << endl;

        cout << "Enter Permission: ";
        Client.Permissions = _ReadPermissionsToSet();

    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full Access ? [Y,N] : ";
        Answer = clsInputValidation::ReadChar();
        if (toupper(Answer) == 'Y')
            return -1;
        string PerArr[] = {"List Client","Add New Client","Delete Client","Update Client","Transactions","Manage Users"};

        for (short i = 0; i <= 5; i++)
        {

            if (clsInputValidation::YesOrNo("\nDo you want to give " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ", PerArr[i]," ]") + "permission ? [Y / N] : "));
                    Permissions += pow(2, i);
        }
        return Permissions;

    }

public:
    
    static void ShowAddNewUser()
    {
        char AddAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tAdd New User Screen";
            _DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

            string UserName = "";
            cout << "\nPLease enter UserName : ";
            UserName = clsInputValidation::ReadString();
            while (clsUser::IsUserExist(UserName))
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nUserName is Already Used, choose another one : ");
                UserName = clsInputValidation::ReadString();
            }

            clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

            _ReadUserInfo(NewUser);

            clsUser::enSaveResults SaveResult;
            SaveResult = NewUser.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << clsUtility::ColorText(clsUtility::enGREEN, "\nUser Addeded Successfully :-)\n");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                clsScreen::_Print(NewUser);
                clsLogs Log(clsLogs::enAddedUser);

                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nError User was not saved because it's Empty");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                break;

            }
            case clsUser::enSaveResults::svFalidAccountNumberExist:
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nError User was not saved because account number is used!\n");
                cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                break;
            }

            }
            AddAgainMessage = clsInputValidation::ReadChar("Do you want to add another User? (Y/N) : ");
        } while (toupper(AddAgainMessage) == 'Y');
    }

};

