#pragma once
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsLogs.h"
#include "clsCurrency.h"



class clsUpdateCurrencyRateScreen : protected clsScreen
{

	static short _GetUpdateChoise()
	{
		cout << "Update By :" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, " [", "1", "] ");
		cout << "Code or" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, " [", "2", "] ");
		cout << "Country or" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, " [", "3", "] ");
		cout << "Both ? : ";

		short Choice = clsInputValidation::ReadNumberBetween<short>(1, 3);
		return Choice;

	}

	static void _UpdateByCode()
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
			_Print(Currnecy);
			_Update(Currnecy);

		}


	}

	static void _UpdateByCountry()
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
			_Print(Currnecy);
			_Update(Currnecy);

		}

	}

	static void _UpdateByBoth()
	{
		cout << "\n\nPLease Enter Country Name : ";
		string Country = clsInputValidation::ReadString();

		cout << "\nPLease Enter CurrencyCode : ";
		string Code = clsInputValidation::ReadString();

		clsCurrency Currnecy = clsCurrency::FindByCountryAndCode(Country, Code);


		if (Currnecy.IsEmpty())
		{
			cout << clsUtility::ColorText(clsUtility::enRED, "\nCurrency is not found");
		}
		else
		{
			_Print(Currnecy);
			_Update(Currnecy);

		}

	}

	static void _Update(clsCurrency Currency)
	{
		if (!clsInputValidation::YesOrNo("\nAre you sure you want to update the rate of this Currency (Y/N) : "))
		{
			cout << clsUtility::ColorText(clsUtility::enRED, "\nUpdating Cancelled");
			return;
		}

		cout << " \nUpdate Currency Rete";
		cout << "\n" << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(21, '-'), "|");
		cout << "\n Enter New Rate : ";
		float Rate = clsInputValidation::clsInputValidation::ReadNumber<float>();
		Currency.UpdateRate(Rate);

		cout << clsUtility::ColorText(clsUtility::enGREEN, "\nCurrency Rate Updated Successfully\n");
		clsLogs Log(clsLogs::enUpdateCurrencyRate);
		_Print(Currency);

	}

public:


	static void UpdateCurrencyScreen()
	{
		char Again = 'n';
		do
		{
			system("cls");

			string Tilte = "\tUpdate Currency Screen";
			_DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);


			short Choise = _GetUpdateChoise();

			switch (Choise)
			{
			case 1:
				_UpdateByCode(); break;
			case 2:
				_UpdateByCountry(); break;
			case 3:
				_UpdateByBoth(); break;
			}

			
			Again = clsInputValidation::ReadChar("\nDo you want to Update another Currency (Y/N) : ");
		} while (toupper(Again) == 'Y');

	}


};

