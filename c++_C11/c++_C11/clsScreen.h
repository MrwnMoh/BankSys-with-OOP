#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsInputValidation.h"
#include "Global.h"
#include "clsDate.h"
#include "clsCurrency.h"

using namespace std;

class clsScreen
{
private:
    static string _PrintDate()
    {
        clsDate Date;
        return Date.DateToString();
    }

    static string _PrintCurrentUserName()
    {
        return CurrentUser.UserName;
    }


protected:

    static void _Print(clsBankClient Client)
    {
        cout << "\n\n\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|");
        cout << clsUtility::ColorText(clsUtility::enYELLOW, "\n>") << "     Client Card";
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      FirstName  : " << Client.FirstName;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      LastName   : " << Client.LastName;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Fullname   : " << Client.FullName();
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Email      : " << Client.Email;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Phone      : " << Client.Phone;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Acc.Number : " << Client.AccountNumber;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Password   : " << Client.PinCode;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Balance    : " << Client.AccountBalance;
        cout << "\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|\n\n");
    }

    static void _PrintClientSummary(clsBankClient Client)
    {
        cout << "\n\n\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|");
        cout << clsUtility::ColorText(clsUtility::enYELLOW, "\n>") << "     Client Card";
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Fullname   : " << Client.FullName();
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Acc.Number : " << Client.AccountNumber;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "      Balance    : " << Client.AccountBalance;
        cout << "\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|\n\n");
    }

    static void _Print(clsUser User)
    {
        cout << "\n\n\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|");
        cout << clsUtility::ColorText(clsUtility::enYELLOW, "\n>") << "    User  Card";
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "     UserName   : " << User.UserName;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "     Fullname   : " << User.FullName();
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "     Email      : " << User.Email;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "     Phone      : " << User.Phone;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "     Password   : " << User.Password;
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|") << "     Permissions: " << User.Permissions;
        cout << "\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|\n\n");
    }

    static void _Print(clsCurrency Currency)
    {
        cout << "\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|");
        cout << clsUtility::ColorText(clsUtility::enYELLOW, "\n>") << "   Currency  Card";
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|")    << "     Country   : " << Currency.Country();
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|")    << "     Code      : " << Currency.CurrencyCode();
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|")    << "     Name      : " << Currency.CurrencyName();
        cout << clsUtility::ColorText(clsUtility::enRED, "\n|")    << "     Rate(1$)  : " << Currency.Rate();
        cout << "\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|\n\n");
    }

	static void _DrawScreenHeader(string Title, string SubTitle = "",clsUtility::enColor Color = clsUtility::enRED, clsUtility::enColor Color2 = clsUtility::enYELLOW)
	{
        cout << clsUtility::ColorTextBlock(Color, Color2, "|", string(118, '-'), "|");
        cout << "                                        " << Title << "\n";
        
        if (SubTitle != "")
        {
            cout << "\t\t\t\t\t\t  " << SubTitle << endl;
        }
        cout << clsUtility::ColorTextBlock(Color, Color2, "|", string(118, '-'), "|");
        cout << clsUtility::ColorText(clsUtility::enYELLOW, ">") << "User : " << _PrintCurrentUserName() << endl;
        cout << clsUtility::ColorText(clsUtility::enYELLOW, ">") << "Date : " << _PrintDate() << endl;
        cout << clsUtility::ColorTextBlock(Color, Color2, "|", string(118, '-'), "|") << endl;

	}

    static void _ReadClientInfo(clsBankClient& Client)
    {
        if(clsInputValidation::YesOrNo("Do you want to update FirstName? [Y/N] : "))
        {
            cout << "Enter FirstName      : ";
            Client.FirstName = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("Do you want to update LastName? [Y/N] : "))
        {
            cout << "Enter LastName       : ";
            Client.LastName = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("Do you want to update Email? [Y/N] : "))
        {
            cout << "Enter Email          : ";
            Client.Email = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("Do you want to update Phone? [Y/N] : "))
        {
            cout << "Enter Phone          : ";
            Client.Phone = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("Do you want to update PinCode? [Y/N] : "))
        {
            cout << "Enter PinCode        : ";
            Client.PinCode = clsInputValidation::ReadString();
        }

        if (clsInputValidation::YesOrNo("Do you want to update Balance? [Y/N] : "))
        {
            cout << "Enter Account Balance: ";
            Client.AccountBalance = clsInputValidation::ReadNumber<float>();
        }

    }

    static bool _CheckAccessRightes(clsUser::enPermissions Permission)
    {
        if (CurrentUser.CheckAccessPermission(Permission))
            return true;
        else
        {
            system("cls");
            _DrawScreenHeader("Acces Denied! Conttact Your Admin..");
            return false;
        }
    }

};

