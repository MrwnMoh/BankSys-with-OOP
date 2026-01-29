#pragma once
#include <iostream>
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsUser.h"
#include "Global.h"
#include "clsLogs.h"

class clsUpdateUserScreen : protected clsScreen
{

    static void _ReadUserInfo(clsUser& Client)
    {
        cout << "\n\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|") << endl;
        if (clsInputValidation::YesOrNo("\nDo you want to Update " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ","FirstName", " ]") + " ? [Y / N] : "))
        {
            cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter FirstName      : ";
            Client.FirstName = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("\nDo you want to Update " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ", "LastName", " ]") + " ? [Y / N] : "))
        {
            cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter LastName       : ";
            Client.LastName = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("\nDo you want to Update " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ", "Email", " ]") + " ? [Y / N] : "))
        {
            cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter Email          : ";
            Client.Email = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("\nDo you want to Update " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ", "Phone", " ]") + " ? [Y / N] : "))
        {
            cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter Phone          : ";
            Client.Phone = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("\nDo you want to Update " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ", "Password", " ]") + " ? [Y / N] : "))
        {
            cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", "> ") << "Enter Password       : ";
            Client.Password = clsInputValidation::ReadString();
        }

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(50, '-'), "|") << endl;

        if (clsInputValidation::YesOrNo("\nDo you want to Update " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ", "Permission", " ]") + " ? [Y / N] : "))
        {
            cout << "Enter Permission: ";
            Client.Permissions = _ReadPermissionsToSet();
        }

    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        if(clsInputValidation::YesOrNo(clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "\n[ ", "Do you want to give full Access ? [Y,N] : ", " ]")))
            return -1;

        string PerArr[] = { "List Client","Add New Client","Delete Client","Update Client","Find Client","Transactions","Manage Users","Currency Exhange" };

        
        for (short i = 0; i <= 7; i++)
        {
        
                if (clsInputValidation::YesOrNo("Do you want to give " + clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[ ", PerArr[i], " ]") + "permission ? [Y / N] : "))
                {
                    Permissions |= (1 << i);

                }
        }
        return Permissions == 255 ? -1:Permissions;

    }

public:

	static void ShowUpdateUserScreen()
	{

        

        char UpdateAgainMessage = 'n';
        do
        {
            system("cls");
            string Tilte = "\tUpdate User Screen";
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
            char Answer = clsInputValidation::ReadChar("Are you sure you want to Update this User [y/n] : ");
            if (toupper(Answer) == 'Y')
            {
                
                clsUser::enSaveResults SaveResult;
                if (UserName == CurrentUser.UserName)
                {
                    cout << clsUtility::ColorText(clsUtility::enRED, "\nError: sorry you can't update yourself!");
                    return;
                }
                else

                {
                    if (User.Permissions != -1)
                    {
                        cout << "\n\n    Update User Info:";
                        _ReadUserInfo(User);
                        SaveResult = User.Save();
                    }
                    else
                    {
                        cout << clsUtility::ColorText(clsUtility::enYELLOW, "\nAdmin access detected!. Please enter your password :");
                        string PasswordCheck = clsInputValidation::ReadString();
                        if (PasswordCheck != CurrentUser.Password)
                            SaveResult = clsUser::enSaveResults::svFaildEmptyObject;
                        else
                        {
                            cout << "\n\n    Update User Info:";
                            _ReadUserInfo(User);
                            SaveResult = User.Save();
                        }
                    }
                }

                switch (SaveResult)
                {
                case clsUser::enSaveResults::svSucceeded:
                {
                    cout << clsUtility::ColorText(clsUtility::enGREEN, "\nAccount Updated Successfully..\n");
                    cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '-'), "|");
                    clsScreen::_Print(User);
                    clsLogs Log(clsLogs::enUpdatedUser);

                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << clsUtility::ColorText(clsUtility::enRED, "\nError account was not saved becase it's Empty!!");
                    break;
                }
                }
            }
            UpdateAgainMessage = clsInputValidation::ReadChar("\nDo you want to update another client? (Y/N) : ");
        } while (toupper(UpdateAgainMessage) == 'Y');
	}

};

