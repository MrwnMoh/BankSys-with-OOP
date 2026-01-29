#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class clsTime
{
	

public:

	static string Time()
	{ 
		
		short _Sec = 0;
		short _Min = 0;
		short _Hour = 0;

		time_t now = time(0);
		tm* localTime = localtime(&now);

		_Sec = localTime->tm_sec;
		_Min = localTime->tm_min;
		_Hour = localTime->tm_hour;

		return to_string(_Hour) + "-" + to_string(_Min) + "-" + to_string(_Sec);
	}

	

};

