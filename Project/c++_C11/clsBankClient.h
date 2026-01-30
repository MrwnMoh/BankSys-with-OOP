#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
	 enum enMode {EmptyMode = 0,UpdateMode = 1,AddNewMode = 2,DeleteMode = 3};
	 enMode _Mode;

	 string _AccountNumber;
	 string _PinCode;
	 float _AccountBalance;

	 static clsBankClient _ConvertLineToClientObject(string Line,string Seperator = "#//#")
	 {
		 vector <string> vClientData;
		 vClientData = clsString::Split(Line, Seperator);
		 return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3]
			 , vClientData[4], vClientData[5], stod(vClientData[6]));
	 }

	 static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	 {
		 return Client.FirstName + Seperator + Client.LastName + Seperator + Client.Email + Seperator +
			 Client.Phone + Seperator + Client.AccountNumber + Seperator + Client.PinCode + Seperator + to_string(Client.AccountBalance) + Seperator;
	 }

	 static clsBankClient _GetEmptyClientObject()
	 {
		 return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	 }

	 static vector <clsBankClient> _LoadClientsDataFromFile()
	 {
		 vector <clsBankClient> vClients;
		 fstream Myfile;
		 Myfile.open("Clients.txt", ios::in);

		 if (Myfile.is_open())
		 {
			 string Line;
			 while (getline(Myfile, Line))
			 {
				 clsBankClient Client = _ConvertLineToClientObject(Line);
				 vClients.push_back(Client);
			 }

			 Myfile.close();
		 }
		 else
			 cout << "File Not Found\n";
		 return vClients;
	 }

	 static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	 {
		 fstream Myfile;
		 Myfile.open("Clients.txt", ios::out);

		 if (Myfile.is_open())
		 {
			 string DataLine;
			 for (clsBankClient C : vClients)
			 {
				 if(C._Mode != DeleteMode)
				 {
					 DataLine = _ConvertClientObjectToLine(C);
					 Myfile << DataLine << endl;
				 }
			 }

			 Myfile.close();
		 }
	 }

	 void _AddNew()
	 {
		 _AddDataLineToFile(_ConvertClientObjectToLine(*this));
	 }

	 void _AddDataLineToFile(string  stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }

	 }

	 void _Update()
	 {
		 vector <clsBankClient> _vClients;
			 _vClients = _LoadClientsDataFromFile();

		 for (clsBankClient&  C : _vClients)
		 {
			 if (C.AccountNumber == AccountNumber)
			 {
				 C = *this;
				 break;
			 }
		 }
		 _SaveClientsDataToFile(_vClients);

	 }

	 void _Delete()
	 {
		 vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		 for (clsBankClient& C : vClients)
		 {
			 if (C.AccountNumber == _AccountNumber)
			 {
				 C._Mode = DeleteMode;
				 _SaveClientsDataToFile(vClients);
				 *this = _GetEmptyClientObject();
			 }
		 }

	 }

public:

	clsBankClient(enMode Mode, string FirsName, string LastName, string Email, string Phone, string AccountNumber,
		string PinCode, float AccountBalance) : clsPerson(FirsName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	void SetAccountNumber(string AccountNumber)
	{
		_AccountNumber = AccountNumber;
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		fstream Myfile;
		for (clsBankClient& Client : vClients)
		{
			if (Client.AccountNumber == AccountNumber)
			{
				return Client;
			}
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		fstream Myfile;
		for (clsBankClient& Client : vClients)
		{
			if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
			{
				return Client;
			}
		}
		return _GetEmptyClientObject();
	}

	static bool IsUserExist(string AccountName)
	{
		clsBankClient Client = clsBankClient::Find(AccountName);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svFalidAccountNumberExist = 2,svFaildDeleted = 3};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			if (IsUserExist(AccountNumber)) //second check
			{
				return enSaveResults::svFalidAccountNumberExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return svSucceeded;
			}
		}

		case enMode::DeleteMode:
		{
			if (IsUserExist(AccountNumber))
			{
				_Delete();
				return svSucceeded;

			}
			else
			{
				return enSaveResults::svFaildDeleted;
			}
		}
		}
	}

	static clsBankClient GetAddNewUserObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enSaveResults Delete()
	{
		_Mode = DeleteMode;
		return Save();
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		double TotalBalances = 0;
		vector <clsBankClient> vClients = GetClientsList();

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C._AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	void Withdraw(double Amount)
	{
		_AccountBalance -= Amount;
		Save();
	}

	void Transfer(double Amount, clsBankClient& DetinationClinet)
	{
		Withdraw(Amount);
		DetinationClinet.Deposit(Amount);
	}

};

