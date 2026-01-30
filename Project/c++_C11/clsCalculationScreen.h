#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsCurrency.h"
#include "clsLogs.h"


class clsCalculationScreen : protected clsScreen
{

	static clsCurrency _ReadCurrency()
	{

		string  Code = clsInputValidation::ReadString();
		clsCurrency Currnecy = clsCurrency::FindByCode(Code);


		while (Currnecy.IsEmpty())
		{
			cout << clsUtility::ColorText(clsUtility::enRED, "\nCurrency is not found");
			cout << "\nPlease enter again : ";

			Code = clsInputValidation::ReadString();
			Currnecy = clsCurrency::FindByCode(Code);

		}

		return Currnecy;

	}

	static float _ReadAmountEx()
	{
		cout << "\n\nEnter Amount to exhange : ";
		float Amount = clsInputValidation::clsInputValidation::ReadNumber<float>();
		while (Amount <= 0)
		{
			cout << clsUtility::ColorText(clsUtility::enRED, "Amount must be greater than zero. Please try again: ");
			Amount = clsInputValidation::clsInputValidation::ReadNumber<float>();
		}
		return Amount;
	}

	static void _ExhangeResulat(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		cout << "\n    Convert From : ";
		_Print(CurrencyFrom);

		float AmonutInUsd = Amount / CurrencyFrom.Rate();

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmonutInUsd << " " << "USD";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}


		cout << "\n\nConverting from USD to:";
		cout << "\n\n         To : ";
		_Print(CurrencyTo);

		float AmonutInCurrencyToCode = AmonutInUsd * CurrencyTo.Rate();


		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmonutInCurrencyToCode << " " << CurrencyTo.CurrencyCode();
		cout << "\n\n";


	}



public:

	static void ShowCurrencyCalculator()
	{

		char Again = 'n';
		do
		{
			system("cls");

			string Tilte = "\tCurrency Calculator Screen";
			_DrawScreenHeader(Tilte, "", clsUtility::enRED, clsUtility::enYELLOW);

			cout << "\n\nPLease Enter Currency1 Code : ";
			clsCurrency Currency1 = _ReadCurrency();

			cout << "\n\nPLease Enter Currency2 Code : ";
			clsCurrency Currency2 = _ReadCurrency();

			float Amount = _ReadAmountEx();

			_ExhangeResulat(Currency1, Currency2, Amount);
			clsLogs Log(clsLogs::enCalculateCurrencies);

			Again = clsInputValidation::ReadChar("\n\nDo you want to perform another calculation? (Y/N) : ");
		} while (toupper(Again) == 'Y');

	}




















};

