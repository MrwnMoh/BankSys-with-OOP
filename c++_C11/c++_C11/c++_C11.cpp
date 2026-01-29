#include <iostream>
#include "clsLoginScreen.h"
using namespace std;

template <class T> class Calculater 
{

private: 
    
    T Number1, Number2;



public:

    Calculater(T n1, T n2)
    {
        Number1 = n1;
        Number2 = n2;
    }

    void Print()
    {
        cout << "Numbers : " << Number1 << " , " << Number2 << ".\n";
        cout << Number1 << " + " << Number2 << " = " << Add() << endl;
        cout << Number1 << " - " << Number2 << " = " << Subtract() << endl;
        cout << Number1 << " * " << Number2 << " = " << Multiply() << endl;
        cout << Number1 << " / " << Number2 << " = " << Divide() << endl;
    }

    T Add()
    {
        return Number1 + Number2;
    }

    T Subtract()
    {
        return Number1 - Number2;
    }

    T Multiply()
    {
        return Number1 * Number2;
    }

    T Divide()
    {
        return Number1 / Number2;
    }

};

int main()
{
   
    clsLoginScreen::ShowLoginScreen();


    /*Calculater <int> IntCalc(2, 2);
    Calculater <float> FloatCalc(2.2, 2.2);
    Calculater <double> DoubleCalc(2.2, 2.2);
    Calculater <char> CharCalc('a','b');


    cout << "\n\nInt Result : \n";IntCalc.Print();
    cout << "\n\nFloat Result : \n"; FloatCalc.Print();
    cout << "\n\ndouble Result : \n"; DoubleCalc.Print();
    cout << "\n\nchar Result : \n"; CharCalc.Print();




*/











    return 0;
}
