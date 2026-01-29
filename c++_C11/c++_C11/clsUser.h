	#pragma once
	#include <iostream>
	#include <string>
	#include <vector>
	#include <fstream>
	#include "clsString.h"
	#include "clsPerson.h"
	#include "clsCrypt.h"

	using namespace std;

	class clsUser : public clsPerson
	{
	private:
		enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
		enMode _Mode;

		string _UserName;
		string _Password;
		int _Permissions;
		static int Rnumber;



		static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
		{
			vector <string> vUserData;
			
			vUserData = clsString::Split(Line, Seperator);
			return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3]
				, vUserData[4], clsCrypt::Decryption(vUserData[5]), stod(vUserData[6]));
		}

		static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
		{
			return User.FirstName + Seperator + User.LastName + Seperator + User.Email + Seperator +
				User.Phone + Seperator + User.UserName + Seperator + clsCrypt::Encryption(User.Password) + Seperator + to_string(User.Permissions) + Seperator;
		}

		static clsUser _GetEmptyUserObject()
		{
			return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
		}

		static vector <clsUser> _LoadUsersDataFromFile()
		{
			vector <clsUser> vUsers;
			fstream Myfile;
			Myfile.open("Users.txt", ios::in);

			if (Myfile.is_open())
			{
				string Line;
				while (getline(Myfile, Line))
				{
					clsUser Client = _ConvertLineToUserObject(Line);
					vUsers.push_back(Client);
				}

				Myfile.close();
			}
			else
				cout << "File Not Found\n";
			return vUsers;
		}

		static void _SaveUsersDataToFile(vector <clsUser> vUsers)
		{
			fstream Myfile;
			Myfile.open("Users.txt", ios::out);

			if (Myfile.is_open())
			{
				string DataLine;
				for (clsUser User : vUsers)
				{
					if (User._Mode != DeleteMode)
					{
						DataLine = _ConvertUserObjectToLine(User);
						Myfile << DataLine << endl;
					}
				}

				Myfile.close();
			}
		}

		void _AddNew()
		{
			_AddDataLineToFile(_ConvertUserObjectToLine(*this));
		}

		void _AddDataLineToFile(string  stDataLine)
		{
			fstream MyFile;
			MyFile.open("Users.txt", ios::out | ios::app);

			if (MyFile.is_open())
			{

				MyFile << stDataLine << endl;

				MyFile.close();
			}

		}

		void _Update()
		{
			vector <clsUser> _vUsers;
			_vUsers = _LoadUsersDataFromFile();

			for (clsUser& User : _vUsers)
			{
				if (User.UserName == UserName)
				{
					User = *this;
					break;
				}
			}
			_SaveUsersDataToFile(_vUsers);

		}

		void _Delete()
		{
			vector <clsUser> vUsers = _LoadUsersDataFromFile();

			for (clsUser& User : vUsers)
			{
				if (User.UserName == _UserName)
				{
					User._Mode = DeleteMode;
					_SaveUsersDataToFile(vUsers);
					*this = _GetEmptyUserObject();
				}
			}

		}

	public:

		enum enPermissions { epAll = -1, epListClient = 1, epAddClient =2 , epDeleteClient = 4, epUpdateClient = 8,
							 epFindClient = 16, epTransacion = 32, epManageUsers = 64 , epCurrencyExhange = 128};

		clsUser(enMode Mode, string FirsName, string LastName, string Email, string Phone, string UserName,
			string Password, int Permissions) : clsPerson(FirsName, LastName, Email, Phone)
		{
			_Mode = Mode;
			_UserName = UserName;
			_Password = Password;
			_Permissions = Permissions;
		}

		void SetUserName(string UserName)
		{
			_UserName = UserName;
		}
		string GetUserName()
		{
			return _UserName;
		}
		__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

		void SetPassword(string Password)
		{
			_Password = Password;
		}
		string GetPassword()
		{
			return _Password;
		}
		__declspec(property(get = GetPassword, put = SetPassword)) string Password;

		void SetPermissions(int Permissions)
		{
			_Permissions = Permissions;
		}
		int GetPermissions()
		{
			return _Permissions;
		}
		__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

		bool IsEmpty()
		{
			return (_Mode == enMode::EmptyMode);
		}

		static clsUser Find(string UserName)
		{
			vector <clsUser> vUsers = _LoadUsersDataFromFile();
			fstream Myfile;
			for (clsUser& User : vUsers)
			{
				if (User.UserName == UserName)
				{
					return User;
				}
			}
			return _GetEmptyUserObject();
		}

		static clsUser Find(string UserName, string Password)
		{
			vector <clsUser> vUsers = _LoadUsersDataFromFile();
			fstream Myfile;
			for (clsUser& User : vUsers)
			{
				if (User.UserName == UserName && User.Password == Password)
				{
					return User;
				}
			}
			return _GetEmptyUserObject();
		}

		static bool IsUserExist(string UserName)
		{
			clsUser User = clsUser::Find(UserName);
			return (!User.IsEmpty());
		}

		enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFalidAccountNumberExist = 2, svFaildDeleted = 3 };

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
				if (IsUserExist(UserName)) //second check
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
				if (IsUserExist(UserName))
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

		static clsUser GetAddNewUserObject(string UserName)
		{
			return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
		}

		enSaveResults Delete()
		{
			_Mode = DeleteMode;
			return Save();
		}

		static vector <clsUser> GetUsersList()
		{
			return _LoadUsersDataFromFile();
		}

		bool CheckAccessPermission(enPermissions Permission)
		{
			if (this -> Permissions == enPermissions::epAll)
				return true;

			if ((Permission & this->Permissions) == Permission)
				return true;
			return false;
		}

		static void Refresh()
		{
			_SaveUsersDataToFile(_LoadUsersDataFromFile());

		}

};
