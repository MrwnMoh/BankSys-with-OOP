#pragma once
#include <iostream>
#include <string>
using namespace std;

class InterfaceCominication
{
public:

	virtual void SendEmail(string, string) = 0;
	virtual void SendFax(string, string) = 0;
	virtual void SendSMS(string, string) = 0;


};

