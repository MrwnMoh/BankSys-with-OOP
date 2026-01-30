#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "clsDate.h"
#include <vector>

using namespace std;
class clsUtility
{

public:

    enum enColor { enRED = 0, enGREEN = 1, enYELLOW = 2, enBLUE = 3, enMAGENTA = 4, enCYAN = 5, enWHITE = 6, enLIGHTGREEN = 7};

    static string ColorText(enColor Color,string Text)
    {
        switch (Color)
        {
        case enRED :
            return  "\033[31m" + Text + "\033[0m";
            
        case enGREEN :
            return "\033[32m" + Text + "\033[0m";

        case enYELLOW:
            return "\033[33m" + Text + "\033[0m";

        case enBLUE:
            return "\033[34m" + Text + "\033[0m";

        case enMAGENTA:
            return "\033[35m" + Text + "\033[0m";

        case enCYAN:
            return "\033[36m" + Text + "\033[0m";

        case enLIGHTGREEN:
            return "\033[92m" + Text + "\033[0m";

        case enWHITE:
            return "\033[0m" + Text + "\033[0m";

        }

    }

    static string ColorTextBlock(enColor Color, string Begain, string Text, string End)
    {
        return ColorText(Color, Begain) + ColorText(Color, Text) + ColorText(Color, End);
    }
    static string ColorTextBlock(enColor Color, enColor Color2,string Begain, string Text)
    {
        return ColorText(Color, Begain) + ColorText(Color2, Text);
    }
    static string ColorTextBlock(enColor Color, enColor Color2, string Begain, string Text, string End)
    {
        return ColorText(Color, Begain) + ColorText(Color2, Text) + ColorText(Color, End);
    }
    static string ColorTextBlock(enColor Color, enColor Color2, string Begain, string Text, string End,string Text2)
    {
        return ColorText(Color, Begain) + ColorText(Color2, Text) + ColorText(Color, End) + Text2;
    }


    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        case MixChars:
            return char(RandomNumber(33, 122));
        }
        return '\0';
    }

    static bool GetRandomBoolean()
    {
        return RandomNumber(0, 1);
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        std::string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }
      
    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        std::string Key = "";
        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);
        return Key;
    }
      
    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << std::endl;
        }
    }
      
    static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }
      
    static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);
    }
      
    static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }
    
    static vector <int> getVectorOfRandomNumbers(int Length, int From, int To)
    {
        vector <int> Vnums(Length);
        for (int i = 0; i < Length; i++)
            Vnums[i] = RandomNumber(From, To);
        return Vnums;
    }

    static vector <string> GetVectorWithRandomWords( int Length, enCharType CharType, short Wordlength)
    {
        vector <string> Vstr(Length);
        for (int i = 0; i < Length; i++)
            Vstr[i] = GenerateWord(CharType, Wordlength);
        return Vstr;
    }

    static vector <char> GetVectorWithRandomCharaters(int Length, enCharType CharType)
    {
        vector <char> Vchar(Length);
        for (int i = 0; i < Length; i++)
            Vchar[i] = GetRandomCharacter(CharType);
        return Vchar;
    }

    static void Swap(int& A, int& B)
    {
        int Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(short& A, short& B)
    {
        short Temp = A;
        A = B;
        B = Temp;
    }
      
    static void Swap(double& A, double& B)
    {
        double Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(float& A, float& B)
    {
        float Temp = A;
        A = B;
        B = Temp;
    }
      
    static void Swap(bool& A, bool& B)
    {
        bool Temp = A;
        A = B;
        B = Temp;
    }
      
    static void Swap(char& A, char& B)
    {
        char Temp = A;
        A = B;
        B = Temp;
    }
      
    static void Swap(string& A, string& B)
    {
        string Temp = A;
        A = B;
        B = Temp;
    }
      
    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::Swab(A, B);
    }
      
    static void ShuffleArray(int arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }
      
    static void ShuffleArray(std::string arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }
      
    static string Tabs(short NumberOfTabs)
    {
        string t = "";
        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
        }
        return t;
    }
      
    static string EncryptText(std::string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }
      
    static string DecryptText(std::string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

    static bool IsNumberBetween(int num,int from, int to)
    {
        return num >= from && num <= to;
    }

};