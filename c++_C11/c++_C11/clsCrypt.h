#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsString.h"

using namespace std;
class clsCrypt
{


	static string _EncryptText(string Text, string Key)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = Text[i] ^ Key[i % Key.length()];

		}
		return Text;
	}
	static string _AddRandomPadding(string Text, string Key)
	{

		string Prefix = "";
		string Suffix = "";
		int paddingSize = Key.length() * 2;

		for (int i = 0; i < paddingSize; i++)
		{
			Prefix += char(clsUtility::RandomNumber(65, 90)); 
			Suffix += char(clsUtility::RandomNumber(65, 90)); 
		}

		return Prefix + Text + Suffix;
	}
	static string _InvertTextCase(string EncryptionText)
	{
		return clsString::InvertCase(EncryptionText);
	}
	static string TextToHex(string Text)
	{
		string HexResult = "";
		for (int i = 0; i < Text.length(); i++)
		{
			char buffer[3];
			sprintf(buffer, "%02X", (unsigned char)Text[i]);
			HexResult += buffer;
		}
		return HexResult;
	}

	static string HexToText(string HexText)
	{
		string TextResult = "";
		for (int i = 0; i < HexText.length(); i += 2)
		{
			string part = HexText.substr(i, 2);
			char ch = (char)strtol(part.c_str(), NULL, 16);
			TextResult += ch;
		}
		return TextResult;
	}
	static string _RemoveRandomPadding(string Text, string Key)
	{
		int prefixLen = Key.length() * 2;
		int suffixLen = Key.length() * 2;

		int originalLength = Text.length() - (prefixLen + suffixLen);

		return Text.substr(prefixLen, originalLength);

	}
	static string _DecryptionText(string Text, string Key)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = Text[i] ^ Key[i % Key.length()];;
		}
		return Text;
	}
	static string _RemoveInvertTextCase(string EncryptionText)
	{
		return clsString::InvertCase(EncryptionText);
	}


public: 


	static string Encryption(string Text, string Key = "Marwan")
	{
		string Encrypted = _EncryptText(_InvertTextCase(_AddRandomPadding(_EncryptText(Text, Key), Key)), Key);

		return TextToHex(Encrypted);
	}

	static string Decryption(string HexText, string Key = "Marwan")
	{
		string EncryptedText = HexToText(HexText);

		string Step1 = _DecryptionText(EncryptedText, Key);
		string Step2 = _RemoveInvertTextCase(Step1);
		string cleanText = _RemoveRandomPadding(Step2, Key);

		return _DecryptionText(cleanText, Key);
	}



};

