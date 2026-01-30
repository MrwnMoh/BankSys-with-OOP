#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:

	string _Value;

	static bool IsLetterVowel(char chr)
	{
		chr = tolower(chr);
		return (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u');
	}

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetString(string Value)
	{
		_Value = Value;
	}

	string GetString()
	{
		return _Value;
	}

	__declspec(property(get = GetString, put = SetString)) string Value;

	//////////////////////////////////////////////////

	//1
	static string LowerAllLetters(string str)
	{

		for (short i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}
	string LowerAllLetters()
	{
		return LowerAllLetters(_Value);
	}

	//2
	static string Invert(string str)
	{
		string str2 = str;

		for (short i = 0; i < str.length(); i++)
		{
			str2[i] = str[str.length() - 1 - i];
		}
		return str2;
	}
	string Invert()
	{
		return Invert(_Value);
	}

	//3
	static string InvertCase(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			isupper(str[i]) ? str[i] = tolower(str[i]) : str[i] = toupper(str[i]);
		}
		return str;
	}
	string InvertCase()
	{
		return InvertCase(_Value);
	}

	//4
	static short CountWords(string Value)
	{
		string delim = " ";
		short pos = 0;
		string sWord;
		short res = 0;

		while ((pos = Value.find(delim)) != string::npos)
		{
			sWord = Value.substr(0, pos);
			if (sWord != "")
			{
				res++;
			}
			Value.erase(0, pos + delim.length());
		}

		if (Value != "")
		{
			res++;
		}
		return res;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	//5
	static void PrintFisrtLetterOfEachWord(string string)
	{

		bool isFirstLetter = true;
		cout << "\nFirst letters of this string : \n";

		for (short i = 0; i < string.length(); i++)
		{
			if (string[i] != ' ' && isFirstLetter)
				cout << string[i] << endl;

			isFirstLetter = (string[i] == ' ' ? true : false);


		}
	}
	void PrintFisrtLetterOfEachWord()
	{
		PrintFisrtLetterOfEachWord(_Value);
	}

	//6
	static string UpperFirstLeterOfEachWord(string str)
	{

		bool isFirstLetter = true;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
				str[i] = toupper(str[i]);

			isFirstLetter = (str[i] == ' ' ? true : false);


		}
		return str;
	}
	string UpperFirstLeterOfEachWord()
	{
		return UpperFirstLeterOfEachWord(_Value);
	}

	//7
	static 	string LowerFirstLeterOfEachWord(string str)
	{


		bool isFirstLetter = true;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
				str[i] = tolower(str[i]);

			isFirstLetter = (str[i] == ' ' ? true : false);


		}
		return str;
	}
	string LowerFirstLeterOfEachWord()
	{
		return LowerFirstLeterOfEachWord(_Value);
	}

	//8
	static string UpperAllLetters(string str)
	{

		for (short i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}
	string UpperAllLetters()
	{
		return UpperAllLetters(_Value);
	}

	//9
	static short CountCapitalLetters(string str)
	{
		short letters = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
				letters++;
		}
		return letters;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	//10
	static short CountSmallLetters(string str)
	{
		short letters = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (islower(str[i]))
				letters++;
		}
		return letters;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	//11
	static short CountLetter(string str, char Lit, bool matchCase)
	{
		short letters = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (matchCase)
			{
				if (str[i] == Lit)
					letters++;
			}
			else
			{
				if (tolower(str[i]) == tolower(Lit))
					letters++;
			}
		}

		return letters;
	}
	short CountLetter(char Lit, bool matchCase)
	{
		return CountLetter(_Value, Lit, matchCase);
	}

	//12
	static short CountVowels(string str)
	{
		short res = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (IsLetterVowel(str[i]))
				res++;
		}
		return res;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	//13
	static void PrintVowels(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			if (IsLetterVowel(str[i]))
				cout << str[i] << "    ";
		}
	}
	void PrintVowels()
	{
		PrintVowels(_Value);
	}

	//14
	static void PrintEachWord(string s1)
	{
		string delim = " ";
		short pos = 0;
		string sWord;

		while ((pos = s1.find(delim)) != string::npos)
		{
			sWord = s1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			s1.erase(0, pos + delim.length());
		}

		if (s1 != "")
		{
			cout << s1 << endl;
		}

	}
	void PrintEachWord()
	{
		PrintEachWord(_Value);
	}

	//15
	static vector <string> Split(string s1, string delim)
	{
		short pos = 0;
		string sWord;
		vector <string> vSplit;

		while ((pos = s1.find(delim)) != string::npos)
		{
			sWord = s1.substr(0, pos);
			if (sWord != "")
			{
				vSplit.push_back(sWord);
			}
			s1.erase(0, pos + delim.length());
		}

		if (s1 != "")
		{
			vSplit.push_back(s1);

		}
		return vSplit;
	}
	vector <string> Split(string delim)
	{
		return Split(_Value, delim);
	}

	//16
	static string TrimLeft(string s1)
	{
		for (short i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ')
				return s1.substr(i);
		}
		return "";
	}
	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

	//17
	static string TrimRight(string s1)
	{
		for (short i = s1.length() - 1; i > 0; i--)
		{
			if (s1[i] != ' ')
				return s1.substr(0, i + 1);
		}
		return "";
	}
	string TrimRight()
	{
		return TrimRight(_Value);
	}

	//18
	static string Trim(string s1)
	{
		return(TrimLeft(TrimRight(s1)));
	}
	string Trim()
	{
		return Trim(_Value);
	}

	//19
	static string JoinString(vector <string> vStr, string delmitr)
	{
		string StrWords;
		for (short i = 0; i < vStr.size(); i++)
		{
			if (i != vStr.size() - 1)
				StrWords += vStr[i] + delmitr;
			else
				StrWords += vStr.at(i);
		}
		return StrWords;

	}

	//20
	static string JoinString(string arrStr[], short arrLenght, string delmitr)
	{
		string StrWords;
		for (short i = 0; i < arrLenght; i++)
		{
			if (i != arrLenght - 1)
				StrWords += arrStr[i] + delmitr;
			else
				StrWords += arrStr[i];
		}
		return StrWords;

	}

	//21
	static string ReverseWords(string str)
	{
		vector<string> vStr;
		string s2 = "";

		vStr = Split(str, " ");

		vector<string>::iterator iter = vStr.end();


		while (iter != vStr.begin())
		{
			--iter;
			s2 += *iter + " ";
		}
		s2 = s2.substr(0, s2.length() - 1);
		return s2;
	}
	string ReverseWords()
	{
		return ReverseWords(_Value);
	}

	//22
	static string ReplaceWord(string str, string strToReplace, string toReplace)
	{
		short pos = str.find(strToReplace);

		while (pos != std::string::npos)
		{
			str = str.replace(pos, strToReplace.length(), toReplace);
			pos = str.find(strToReplace);
		}

		return str;
	}
	string ReplaceWord(string strToReplace, string toReplace)
	{
		return ReplaceWord(_Value, strToReplace, toReplace);
	}

	//23
	static string RemovePauncations(string str)
	{
		string s2 = "";
		for (short i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
			{
				s2 += str[i];
			}
		}
		return s2;
	}
	string RemovePauncations()
	{
		return RemovePauncations(_Value);
	}

};
