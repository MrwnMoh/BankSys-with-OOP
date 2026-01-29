#pragma once
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransfareScreen.h"

class clsTransactionsScreen : clsScreen
{
	enum enTransactionsOptions {
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,
		eTransfare = 4 , eMainMenue = 5};

	static short _ReadTransactionsOption()
	{
		cout << "Choose what do you want " << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1,5", "] : ");
		short Choice = clsInputValidation::ReadNumberBetween<short>(1, 5);
		return Choice;
	}

	static void _PereformTransactionsOptions(enTransactionsOptions enTransacions)
	{
		switch (enTransacions)
		{
		case clsTransactionsScreen::eDeposit:
			_ShowDepositScreen();
			break;
		case clsTransactionsScreen::eWithdraw:
			_ShowWithdrawScreen();
			break;
		case clsTransactionsScreen::eTotalBalances:
			_ShowTotalBalancesScreen();
			break;
		case clsTransactionsScreen::eTransfare:
			_ShowTranfareScreen();
			break;
		default:
			break;
		}
		if(enTransacions != clsTransactionsScreen::eMainMenue)
		    _GoBackToTransactionsMenue();
	}

	static  void _GoBackToTransactionsMenue()
	{
		cout << "\nPress any key to go back to Transactions Menue...\n";
		system("pause>0");
		ShowTransactionsScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTranfareScreen()
	{
		clsTransfareScreen::ShowTransfareScreen();
	}

public:

	static void ShowTransactionsScreen()
	{
		if (!_CheckAccessRightes(clsUser::enPermissions::epTransacion))
			return;

		system("cls");
		_DrawScreenHeader("\t\tTransactions Screen");

		cout << "\n\n";
		cout << clsUtility::ColorTextBlock(clsUtility::enYELLOW, "|", string(118, '='), "|");
		cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
		cout << clsUtility::ColorTextBlock(clsUtility::enYELLOW, "|", string(118, '='), "|");

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1", "]");
		cout << " Deposit.\n";

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "2", "]");
		cout << " Withdraw.\n";

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "3", "]");
		cout << " Total Balances.\n";

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "4", "]");
		cout << " Transfer.\n";

		cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "5", "]");
		cout << " Main Menue.\n";

		cout << clsUtility::ColorTextBlock(clsUtility::enYELLOW, "|", string(118, '='), "|");

		cout << endl;
		_PereformTransactionsOptions(enTransactionsOptions(_ReadTransactionsOption()));

	}



};

