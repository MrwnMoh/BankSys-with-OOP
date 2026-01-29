#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsDate.h"
#include <limits>
#include <type_traits>


using namespace std;
class clsInputValidation
{

public:

	template <typename T>
	static T ReadNegativeNumber(string InvalidMessage = "\nNumber must be negative, enter again : ")
	{
		T num;
		do
		{
			num = ReadNumber<T>(InvalidMessage);
		} while (num >= 0);
		return num;
	}

	template <typename T> 
	static T ReadNumber(string InvalidMessage = "\nInvalid Number, Enter again : ")
	{
		string strNum;
		cin >> strNum;

		if constexpr (is_integral<T>::value) 
		{
			while (!IsOnlyDigit(strNum))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << InvalidMessage;
				cin >> strNum;
			}
			return static_cast<T>(stoi(strNum));
		}
		else if constexpr (is_floating_point<T>::value) 
		{
			while (!IsOnlyDigit(strNum, true))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << InvalidMessage;
				cin >> strNum;
			}
			return static_cast<T>(stod(strNum));
		}
	}

	template <typename T>
	static T ReadPositiveNumber(string InvalidMessage = "\n Number must be positive, enter again : ")
	{
		T num;
		do
		{
			num = ReadNumber<T>(InvalidMessage);
		} while (num <= 0);
		return num;
	}

	static char ReadChar(string massege = "")
	{
		string ch;
		do {
			cout << massege;
			getline(cin >> ws, ch);
		} while (ch.length() != 1);
		return ch[0];
	}

	template <typename T>
	static T ReadNumberBetween(T from, T to,string InvalidMessage = "\nNumber not in range, enter again : ")
	{
		if (from > to)
			clsUtility::Swap(from, to);

		T num;
		num = ReadNumber<T>(InvalidMessage);

		while (num < from || num > to)
		{
			cout << InvalidMessage;
			num = ReadNumber<T>(InvalidMessage);

		}
		return num;
	}

	static bool IsOnlyDigit(string str,bool Double = false)
	{
		if (str.empty())
			return false;
		short ans = 0;
		if (str[0] == '-')
			ans++;

		if(!Double)
		{
			for (int i = 0 + ans; i < str.length(); i++)
			{
				if (!isdigit(str[i]))
				{
					return false;
				}
			}
		}
		else
		{
			for (int i = 0 + ans; i < str.length(); i++)
			{
				if(str[i] != '.')
				{
					if (!isdigit(str[i]))
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	template <typename T>
	static bool IsNumberBetween(T number, T from, T to)
	{
		if (from > to)
			clsUtility::Swap(from, to);

		return (number >= from && number <= to);
	}

	static bool IsDateBetween(clsDate Date, clsDate from, clsDate to)
	{
		if ((Date.IsDateBeforeDate2(to) || Date.IsDateEqualDate2(to)) && (Date.IsDateAfterDate2(from) || Date.IsDateEqualDate2(from)))
			return true;
		else
			clsUtility::Swap(from, to);
		return (Date.IsDateBeforeDate2(to) || Date.IsDateEqualDate2(to)) && (Date.IsDateAfterDate2(from) || Date.IsDateEqualDate2(from));
	}

	static bool isDateValid(clsDate date)
	{
		return date.IsValide();
	}

	static string ReadString()
	{
		string  S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

	static bool YesOrNo(string Text)
	{
		cout << Text;
		char Answer;
		Answer = clsInputValidation::ReadChar();
		return (toupper(Answer) ==  'Y');
	}

};

