#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsUser.h"
#include "Global.h"
#include "clsLogs.h"

class clsDeleteUserScreen : protected clsScreen
{



public:

	static void ShowDeleteUserScreen()
	{
        char DeleteAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tDelete User Screen";
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
            clsScreen::_Print(User);

            char Answer = clsInputValidation::ReadChar("Are you sure you want to delete this User [y/n] : ");
            if (toupper(Answer) == 'Y')
            {
                clsUser::enSaveResults SaveResult;
                if (UserName == CurrentUser.UserName)
                {
                    cout << clsUtility::ColorText(clsUtility::enRED, "\nError: sorry you can't delete yourself!");
                    return;
                }
                else
                {
                    if (User.Permissions != -1)
                    {
                        SaveResult = User.Delete();
                    }
                    else
                    {
                        cout << clsUtility::ColorText(clsUtility::enYELLOW, "\nAdmin access detected!. Please enter your password :");
                        string PasswordCheck = clsInputValidation::ReadString();
                        if (PasswordCheck != CurrentUser.Password)
                            SaveResult = clsUser::enSaveResults::svFaildDeleted;
                        else
                            SaveResult = User.Delete();
                    }
                }
                switch (SaveResult)
                {
                case  clsUser::enSaveResults::svSucceeded:
                {
                    cout << clsUtility::ColorText(clsUtility::enGREEN, "\nUser Deleted Successfully :-)\n");
                    cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                    clsScreen::_Print(User);
                    clsLogs Log(clsLogs::enDeletedUser);

                    break;
                }
                case clsUser::enSaveResults::svFaildDeleted:
                {
                    cout << clsUtility::ColorText(clsUtility::enRED, "\nError: User was not deleted! Admin password is required.");
                    break;
                }

                }
            }
            else
            {
                cout << clsUtility::ColorText(clsUtility::enRED, "\nDelete has been canceled");
            }


            DeleteAgainMessage = clsInputValidation::ReadChar("\nDo you want to delete another User? (Y/N) Or try again : ");
        } while (toupper(DeleteAgainMessage) == 'Y');



	}

};

