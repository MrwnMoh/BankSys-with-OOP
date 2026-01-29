#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsInputValidation.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCalculationScreen.h"

class clsCurrencyExhangeScreen : protected clsScreen
{

    enum enCurrenciesExhangeOptions {
        eListCurrencies = 1, eFindCurrencies = 2, eUpdateRate = 3,
        eCurrenciesCalculater = 4, eMainMenu = 5
    };

    static short _ReadCurrenciesExhangeOption()
    {
        cout << "Choose what do you want " << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1,5", "] : ");
        short Choice = clsInputValidation::ReadNumberBetween<short>(1, 5);
        return Choice;
    }

    static  void _GoBackToCurrenciesExhangeMenu()
    {
        cout << "\nPress any key to go back to Currencies Exhange Menu...\n";
        system("pause>0");
        ShowCurrencyExhangeMenue();
    }

    static void _ListCurrenciesMenu()
    {
        clsListCurrenciesScreen::ShowCurrenciesListScreen();
    }

    static void _FindCurrenciesMenu()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _UpdateRateMenu()
    {
        clsUpdateCurrencyRateScreen::UpdateCurrencyScreen();
    }

    static void _CurrenciesCalculater()
    {
        clsCalculationScreen::ShowCurrencyCalculator();
    }

    static void _PereformCurrenciesExhangeOptions(enCurrenciesExhangeOptions eCurrenciesExhange)
    {
        switch (eCurrenciesExhange)
        {
        case clsCurrencyExhangeScreen::eListCurrencies:
            _ListCurrenciesMenu();
            break;
        case clsCurrencyExhangeScreen::eFindCurrencies:
            _FindCurrenciesMenu();
            break;
        case clsCurrencyExhangeScreen::eUpdateRate:
            _UpdateRateMenu();
            break;
        case clsCurrencyExhangeScreen::eCurrenciesCalculater:
            _CurrenciesCalculater();
            break;
        default:
            break;
        }

        if (eCurrenciesExhange != eMainMenu)
            _GoBackToCurrenciesExhangeMenu();

    }


public:

    static void ShowCurrencyExhangeMenue()
    {
        if (!_CheckAccessRightes(clsUser::enPermissions::epCurrencyExhange))
            return;

        system("cls");
        _DrawScreenHeader("\tCurrency Exhange Main Screen");

        cout << "\n\n";
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");
        cout << setw(37) << left << "" << "\t\t Currency Exhange Menu\n";
        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|");

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "1", "]");
        cout << " List Currencies.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "2", "]");
        cout << " Find Currency.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "3", "]");
        cout << " Update Rate.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "4", "]");
        cout << " Currency Calculater.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "[", "5", "]");
        cout << " Main Menu.\n";

        cout << clsUtility::ColorTextBlock(clsUtility::enRED, clsUtility::enYELLOW, "|", string(118, '='), "|") << endl;

        _PereformCurrenciesExhangeOptions(enCurrenciesExhangeOptions(_ReadCurrenciesExhangeOption()));

    }

};

