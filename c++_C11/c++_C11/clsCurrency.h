#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include <fstream>

class clsCurrency
{

	enum enMode {EmptyMode = 0, UpdateMode = 2};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static vector <clsCurrency> _LoadCurrencyDateFromFile()
	{
		vector <clsCurrency> vCurrencys;
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsCurrency Currency = _ConverLineToCurrencyObject(Line);
				vCurrencys.push_back(Currency);
			}

			Myfile.close();
		}
		else
			cout << "File Not Found\n";
		return vCurrencys;
	}

	static void _SaveCurrencyDateToFile(vector <clsCurrency> vCurrencys)
	{
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::out);

		if (Myfile.is_open())
		{
			string DataLine;
			for (clsCurrency Currency : vCurrencys)
			{
					DataLine = _ConvertCurrencyObjectToLine(Currency);
					Myfile << DataLine << endl;
			}

			Myfile.close();
		}
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		return Currency.Country() + Seperator +
			Currency.CurrencyCode() + Seperator +
			Currency.CurrencyName() + Seperator +
			to_string(Currency.Rate());

	}

	static clsCurrency _ConverLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> vCurrencyData;

		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencyDateFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDateToFile(_vCurrencys);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string currencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = currencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	
	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllLetters(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConverLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
		}
		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllLetters(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConverLineToCurrencyObject(Line);
				if (clsString::UpperAllLetters(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountryAndCode(string Country, string CurrencyCode)
	{
		Country = clsString::UpperAllLetters(Country);
		CurrencyCode = clsString::UpperAllLetters(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConverLineToCurrencyObject(Line);
				if ((clsString::UpperAllLetters(Currency.Country()) == Country) && (Currency.CurrencyCode() == CurrencyCode))
				{
					MyFile.close();
					return Currency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDateFromFile();
	}

};

