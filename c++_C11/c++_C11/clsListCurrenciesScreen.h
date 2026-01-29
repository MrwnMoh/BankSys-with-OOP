#pragma once
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidation.h"
#include "clsUtility.h"
#include "clsCurrency.h"
#include "clsLogs.h"

class clsListCurrenciesScreen : protected clsScreen
{


    static void PrintCurrencyRecordeLine(clsCurrency Currency)
    {
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(40) << Currency.Country();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(10) << Currency.CurrencyCode();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(40) << Currency.CurrencyName();
        cout << clsUtility::ColorText(clsUtility::enRED, "| ") << clsUtility::ColorText(clsUtility::enGREEN, "$ ") << left << setw(18) << Currency.Rate();
        cout << clsUtility::ColorText(clsUtility::enRED, " |");
    }


public:

    static void ShowCurrenciesListScreen()
    {
        
     vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
     clsLogs Log(clsLogs::enListCurrencies);

    system("cls");
    string Title = "\n\t\t\t\t\t\tCurrencies List Screen";
    string SubTitle = clsUtility::ColorTextBlock(clsUtility::enYELLOW, clsUtility::enRED, "(", to_string(vCurrencies.size()), ")", "Currencies(s).\n");
    _DrawScreenHeader(Title, SubTitle, clsUtility::enRED, clsUtility::enYELLOW);
    cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;

    cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(40) << "Country";
    cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(10) << "Code";
    cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(40) << "Name";
    cout << clsUtility::ColorText(clsUtility::enRED, "| ") << left << setw(20) << "Rate(1$)";
    cout << clsUtility::ColorText(clsUtility::enRED, " |") << endl;
    cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;


    if (vCurrencies.size() == 0)
    {
        cout << "\n\t\t\t\t\t\tNo Currencies Abailabe In the System!!";
    }
    else
    {
        for (clsCurrency& C : vCurrencies)
        {
            PrintCurrencyRecordeLine(C);
            cout << endl;

        }
    }
    cout << clsUtility::ColorText(clsUtility::enYELLOW, string(120, '-')) << endl;
    }




};

