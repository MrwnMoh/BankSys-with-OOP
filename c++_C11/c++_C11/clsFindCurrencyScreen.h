#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsLogs.h"

class clsFindCurrencyScreen : protected clsScreen
{
	static short _GetFindChoise()
	{
		cout << "Find By :" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, " [", "1", "] "); 
		cout << "Code or" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, " [", "2", "] ");
		cout << "Country or" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, " [", "3", "] ");
		cout << "Both ? : ";

		short Choice = clsInputValidation::ReadNumberBetween<short>(1, 3);
		return Choice;

	}

	static void _FindByCode()
	{
		cout << "\n\nPLease Enter CurrencyCode : ";
		string Code = clsInputValidation::ReadString();
		clsCurrency Currnecy = clsCurrency::FindByCode(Code);
		


		if (Currnecy.IsEmpty())
		{
			cout << clsUtility::ColorText(clsUtility::enRED, "\nCurrency is not found");
		}
		else
		{
			cout << clsUtility::ColorText(clsUtility::enGREEN, "\nCurrency founded");
			_Print(Currnecy);

		}


	}

	static void _FindByCountry()
	{
		cout << "\n\nPLease Enter Country Name : ";
		string Country = clsInputValidation::ReadString();
		clsCurrency Currnecy = clsCurrency::FindByCountry(Country);



		if (Currnecy.IsEmpty())
		{
			cout << clsUtility::ColorText(clsUtility::enRED, "\nCurrency is not found");
		}
		else
		{
			cout << clsUtility::ColorText(clsUtility::enGREEN, "\nCurrency founded");
			_Print(Currnecy);

		}

	}

	static void _FindByBoth()
	{
		cout << "\n\nPLease Enter Country Name : ";
		string Country = clsInputValidation::ReadString();

		cout << "\nPLease Enter CurrencyCode : ";
		string Code = clsInputValidation::ReadString();

		clsCurrency Currnecy = clsCurrency::FindByCountryAndCode(Country,Code);


		if (Currnecy.IsEmpty())
		{
			cout << clsUtility::ColorText(clsUtility::enRED, "\nCurrency is not found");
		}
		else
		{
			cout << clsUtility::ColorText(clsUtility::enGREEN, "\nCurrency founded");
			_Print(Currnecy);

		}

	}


public:
	
	static void ShowFindCurrencyScreen()
	{
		char Again = 'n';
		do
		{
			system("cls");

			string Tilte = "\tFind Currency Screen";
			_DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

			short Choise = _GetFindChoise();

			switch (Choise)
			{
			case 1:
				_FindByCode(); break;
			case 2:
				_FindByCountry(); break;
			case 3:
				_FindByBoth(); break;
			}
			clsLogs Log(clsLogs::enFoundCurrencis);

			Again = clsInputValidation::ReadChar("\nDo you want to Find another Currency (Y/N) : ");
		} while (toupper(Again) == 'Y');

	}





};

