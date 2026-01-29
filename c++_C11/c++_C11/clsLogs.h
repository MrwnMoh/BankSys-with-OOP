#pragma once
#include <iostream>
#include "clsTime.h"
#include "clsDate.h"
#include "Global.h"
#include <string>
#include "clsString.h"
#include <fstream>
#include <vector>
#include "clsBankClient.h"

using namespace std;

class clsLogs
{

public:
	enum enStatus { enLogin = 0, enLogout = 1 , enSystemLogsLoaded = 2, enUpdatedUser = 3, enDeletedUser = 4,enAddedUser = 5, enTransfer = 6, enTransferLogsLoaded = 7
		          , enUpdatedClient = 8, enDeletedClient = 9, enAddedClient = 10, enFoundClient = 11,enFoundUser = 12, enListUsers = 13, enListClients = 14,
					enUpdateCurrencyRate = 15,enListCurrencies = 16, enFoundCurrencis = 17, enCalculateCurrencies = 18, enListPermissions = 19, enRefreshUsers = 20
				   , enDeposit = 21 , enWithdraw = 22, enTotalBalances = 23};


private:
	string _UserName ;
	string _Password ;
	int _Permissions ;
	string _Timestamp;
	enStatus _Mode;
	string _CurrentStatus;
	string _SuorseClient;
	string _DistinationClient;
	double _SuorseCLBalanceAfterTransfer;
	double _DestinationCLBalanceAfterTransfer;
	double _TransferAmount;


	string _CurrentModeText()
	{
		switch (_Mode)
		{
		case enLogin:  return "Login";
		case enLogout: return "Logout";
		case enSystemLogsLoaded: return "System Logs Loaded";
		case enTransferLogsLoaded: return "Transfer Logs Loaded";
		case enUpdatedUser: return "Updated User";
		case enDeletedUser: return "Deleted User";
		case enAddedUser: return "Added User";
		case enFoundUser: return "Found User";
		case enListUsers: return "Show Users List";
		case enTransfer: return "Transfer";
		case enUpdatedClient: return "Updated Client";
		case enDeletedClient: return "Deleted Client";
		case enAddedClient: return "Added Client";
		case enFoundClient: return "Found Client";
		case enListClients: return "Show Clients List";
		case enUpdateCurrencyRate: return "Currency rate updated";
		case enFoundCurrencis: return "Found Currencis";
		case enListCurrencies: return "Show Currencis List";
		case enCalculateCurrencies: return "Currency Calc";
		case enListPermissions: return "Show Permissions List";
		case enRefreshUsers: return "Refresh Users";
		case enDeposit: return "Deposit";
		case enWithdraw: return "Withdraw";
		case enTotalBalances: return "Show Total Balances";
		default:       return "Unknown Mode";
		}
	}

	  string _ConvertSystemLogsToLine(string Seperator = "#//#")
	{
		 return _CurrentModeText() + Seperator + _Timestamp + Seperator + _UserName + Seperator + _Password + Seperator + to_string(_Permissions);
	}

	  string _ConvertTransferLogsToLine(string Seperator = "#//#")
	  {
		  return _CurrentModeText() + Seperator +
			     _Timestamp + Seperator +
				 _SuorseClient + Seperator +
				 _DistinationClient + Seperator +
				 to_string(_TransferAmount) + Seperator +
				 to_string(_SuorseCLBalanceAfterTransfer) +
				 Seperator + to_string(_DestinationCLBalanceAfterTransfer) +
				 Seperator + _UserName;
	  }

	  void _SaveSystemLogsDataToFile()
	 {
		 fstream Myfile;
		 Myfile.open("Logs.txt", ios::app);

		 if (Myfile.is_open())
		 {
			 string DataLine;
			 DataLine = _ConvertSystemLogsToLine();
			 Myfile << DataLine << endl;
			 Myfile.close();
		 }
	 }

	  void _SaveTransferLogsDataToFile()
	  {
		  fstream Myfile;
		  Myfile.open("TransferLogs.txt", ios::app);

		  if (Myfile.is_open())
		  {
			  string DataLine;
			  DataLine = _ConvertTransferLogsToLine();
			  Myfile << DataLine << endl;
			  Myfile.close();
		  }
	  }

	  static clsLogs _ConverSystemLogLineToLogObject(string LogLine,string Seperator = "#//#")
	  {
		  vector <string> vLogData;
		  vLogData = clsString::Split(LogLine, Seperator);
		  return clsLogs(vLogData[0], vLogData[1], vLogData[2], vLogData[3],stoi(vLogData[4]));
	  }

	  static clsLogs _ConverTransferLogLineToLogObject(string LogLine, string Seperator = "#//#")
	  {
		  vector <string> vLogData;
		  vLogData = clsString::Split(LogLine, Seperator);
		  return clsLogs(vLogData[0], vLogData[1], vLogData[2], vLogData[3], stod(vLogData[4]), stod(vLogData[5]), stod(vLogData[6]), vLogData[7]);
	  }

	  static vector <clsLogs> _LoadSystemLogsFromFile()
	  {
		  vector <clsLogs> vLogs;
		  fstream Myfile;
		  Myfile.open("Logs.txt", ios::in);

		  if (Myfile.is_open())
		  {
			  string Line;
			  while (getline(Myfile, Line))
			  {
				  clsLogs Log = _ConverSystemLogLineToLogObject(Line);
				  vLogs.push_back(Log);
			  }

			  Myfile.close();
		  }
		  else
			  cout << "File Not Found\n";
		  return vLogs;
	  }

	  static vector <clsLogs> _LoadTransferLogsFromFile()
	  {
		  vector <clsLogs> vLogs;
		  fstream Myfile;
		  Myfile.open("TransferLogs.txt", ios::in);

		  if (Myfile.is_open())
		  {
			  string Line;
			  while (getline(Myfile, Line))
			  {
				  clsLogs Log = _ConverTransferLogLineToLogObject(Line);
				  vLogs.push_back(Log);
			  }

			  Myfile.close();
		  }
		  else
			  cout << "File Not Found\n";
		  return vLogs;
	  }


public:

	clsLogs(enStatus Mode)
	{
		 _UserName = CurrentUser.UserName;
		 _Password = CurrentUser.Password;
		 _Permissions = CurrentUser.Permissions;
		 _Timestamp =clsDate::GetDateTime();
		_Mode = Mode;
		_SaveSystemLogsDataToFile();
	}
	clsLogs(string Statuse,string Timesamp,string UserName,string Password,int Permissions)
	{
		 _CurrentStatus = Statuse;
		 _Timestamp = Timesamp;
		 _UserName = UserName;
		 _Password = Password;
		 _Permissions = Permissions;
	}


	clsLogs(enStatus Mode, string SuorseClient, string DistinationClient,double SuorseCLBalanceAfterTransfer,double DestinationCLBalanceAfterTransfer,double TransferAmount)
	{
		_UserName = CurrentUser.UserName;
		_Timestamp = clsDate::GetDateTime();
		_Mode = Mode;
		_SuorseClient = SuorseClient;
		_DistinationClient = DistinationClient;
		_DestinationCLBalanceAfterTransfer = DestinationCLBalanceAfterTransfer;
		_SuorseCLBalanceAfterTransfer = SuorseCLBalanceAfterTransfer;
		_TransferAmount = TransferAmount;
		_SaveTransferLogsDataToFile();
	}
	clsLogs(string Statuse, string Timesamp, string SuorseClient, string DistinationClient, double SuorseCLBalanceAfterTransfer, double DestinationCLBalanceAfterTransfer, double TransferAmount, string UserName)
	{
		_CurrentStatus = Statuse;
		_Timestamp = Timesamp;
		_SuorseClient = SuorseClient;
		_DistinationClient = DistinationClient;
		_SuorseCLBalanceAfterTransfer = SuorseCLBalanceAfterTransfer;
		_DestinationCLBalanceAfterTransfer = DestinationCLBalanceAfterTransfer;
		_TransferAmount = TransferAmount;
		_UserName = UserName;
	}


	string UserName()
	{
		return _UserName;
	}

	string Password()
	{
		return _Password;
	}

	string Timestamp()
	{
		return _Timestamp;
	}

	string Status()
	{
		return _CurrentStatus;
	}

	int Permission()
	{
		return _Permissions;
	}

	string SuorseCL()
	{
		return _SuorseClient;
	}

	string DestinaionCL()
	{
		return _DistinationClient;
	}

	double SuorseClBlncAfTrns()
	{
		return _SuorseCLBalanceAfterTransfer;
	}

	double DesinationClBlncAfTrns()
	{
		return _DestinationCLBalanceAfterTransfer;
	}

	double TransferAmount()
	{
		return _TransferAmount;
	}

	static vector <clsLogs> GetSystemLogsList()
	{
		return _LoadSystemLogsFromFile();
	}

	static vector <clsLogs> GetTransferLogsList()
	{
		return _LoadTransferLogsFromFile();
	}


};

