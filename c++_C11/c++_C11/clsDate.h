#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include "clsString.h"
#include "clsTime.h"

using namespace std;

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;


public:

    clsDate()
    {
        SetSystemDate();
    }

    clsDate(string Date)
    {
        vector <string> Vdate = clsString::Split(Date, "/");
        _Day = stoi(Vdate.at(0));
        _Month = stoi(Vdate.at(1));
        _Year = stoi(Vdate.at(2));
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short Days, short Year)
    {
        *this = GetDateFromDayeOrderInYear(Days, Year);
    }

    //Day
    void SetDay(short Day)
    {
        _Day = Day;
    }
    short GetDay()
    {
        return _Day;
    }
    __declspec(property(get = GetDay, put = SetDay)) short Day;

    //Month
    void SetMonth(short Month)
    {
        _Month = Month;
    }
    short GetMonth()
    {
        return _Month;
    }
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;

    //Year
    void SetYear(short Year)
    {
        _Year = Year;
    }
    short GetYear()
    {
        return _Year;
    }
    __declspec(property(get = GetYear, put = SetYear)) short Year;
    ////////////////////////////////////////////////////////////////

    //1
    static bool IsLeapYear(short year)
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }

    //2
    static short NumberOfDaysInAYear(short Year)
    {
        return IsLeapYear(Year) ? (366) : (365);
    }
    short NumberOfDaysInAYear()
    {
        return NumberOfDaysInAYear(_Year);
    }

    //3
    static short NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }
    short NumberOfHoursInAYear()
    {
        return NumberOfHoursInAYear(_Year);
    }

    //4
    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }
    int NumberOfMinutesInAYear()
    {
        return NumberOfMinutesInAYear(_Year);
    }

    //5
    static long long int NumberOfSecondsInAYear(short Year)
    {
        return (long long)NumberOfMinutesInAYear(Year) * 60;
    }
    long long int NumberOfSecondsInAYear()
    {
        return NumberOfSecondsInAYear(_Year);
    }

    //6
    static short NumberOfDaysInAMounth(short Year, short month)
    {
        if (month < 1 || month > 12)
            return 0;



        int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        return (month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[month - 1];
    }
    short NumberOfDaysInAMounth()
    {
        return NumberOfDaysInAMounth(_Year, _Month);
    }

    //7
    static short NumberOfHoursInAMounth(short Year, short mount)
    {
        return NumberOfDaysInAMounth(Year, mount) * 24;
    }
    short NumberOfHoursInAMounth()
    {
        return NumberOfHoursInAMounth(_Year, _Month);
    }

    //8
    static int NumberOfMinutesInAMounth(short Year, short mount)
    {
        return NumberOfHoursInAMounth(Year, mount) * 60;
    }
    int NumberOfMinutesInAMounth()
    {
        return NumberOfMinutesInAMounth(_Year, _Month);
    }

    //9
    static long long int NumberOfSecondsInAMounth(short Year, short mount)
    {
        return (long long)NumberOfMinutesInAMounth(Year, mount) * 60;
    }
    long long int NumberOfSecondsInAMounth()
    {
        return NumberOfSecondsInAMounth(_Year, _Month);
    }

    //10
    static short DayOrder(short Year, short month, short day)
    {
        short a = (14 - month) / 12;
        short y = Year - a;
        short m = month + (12 * a) - 2;
        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return d;
    }
    static short DayOrder(clsDate date)
    {
        return DayOrder(date._Year, date._Month, date._Day);
    }
    short DayOrder()
    {
        return DayOrder(*this);
    }

    //11
    static string DayName(short DayOrder)
    {
        string arrDays[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
        return  arrDays[DayOrder];
    }
    string DayName()
    {
        return DayName(_Day);
    }

    //12
    static string MonthName(short month)
    {
        string arrMonths[12] = {
                                  "Jan",
                                  "Feb",
                                  "Mar",
                                  "Apr",
                                  "May",
                                  "Jun",
                                  "Jul",
                                  "Aug",
                                  "Sep",
                                  "Oct",
                                  "Nov",
                                  "Dec"
        };

        return arrMonths[month - 1];
    }
    string MonthName()
    {
        return MonthName(_Month);
    }

    //13
    static void PrintMonthCalinder(short Year, short month)
    {
        cout << " ____________" << MonthName(month) << "____________";
        cout << "\n Sun Mon Tue Wed Thu Fri Sat\n";
        short MonthDays = NumberOfDaysInAMounth(Year, month);
        short current = DayOrder(Year, month, 1);
        short i;
        for (i = 0; i < current; i++)
            cout << "    ";

        for (short j = 1; j <= MonthDays; j++)
        {
            printf("%4d", j);
            if (++i == 7)
            {
                i = 0;
                cout << "\n";

            }
        }
        cout << "\n_____________________________\n\n";
    }
    void PrintMonthCalinder()
    {
        PrintMonthCalinder(_Year, Month);
    }

    //14
    static void PrintYearCalineder(short Year)
    {
        cout << "\n _____________________________\n\n";
        for (short i = 1; i <= 12; i++)
        {
            cout << " ____________" << Year << "___________\n";
            PrintMonthCalinder(Year, i);
        }
    }
    void PrintYearCalineder()
    {
        PrintYearCalineder(_Year);
    }

    //15
    static short NumberOfDaysFromTheBeginingOfTheYear(short Year, short month, short day)
    {
        short tDays = 0;
        for (short i = 1; i < month; i++)
        {
            tDays += NumberOfDaysInAMounth(Year, i);
        }
        tDays += day;
        return tDays;
    }
    short NumberOfDaysFromTheBeginingOfTheYear()
    {
        return NumberOfDaysFromTheBeginingOfTheYear(_Year, _Month, _Day);
    }
    static short NumberOfDaysFromTheBeginingOfTheYear(clsDate date)
    {
        return NumberOfDaysFromTheBeginingOfTheYear(date._Year, date._Month, date._Day);
    }

    //16
    static clsDate GetDateFromDayeOrderInYear(short tDays, short year)
    {
        clsDate date;
        short monthDays = 0;
        short Remining = tDays;
        date._Year = year;
        date._Month = 1;

        while (true)
        {
            monthDays = NumberOfDaysInAMounth(year, date._Month);
            if (Remining > monthDays)
            {
                Remining -= monthDays;
                date._Month++;
            }
            else
            {
                date._Day = Remining;
                break;
            }
        }
        return date;
    }
    void GetDateFromDayeOrderInYear(short tDays)
    {
        *this = GetDateFromDayeOrderInYear(tDays, _Year);
    }

    //17
    static clsDate AddDays(short Year, short month, short day, int AddingDays)
    {
        clsDate date;
        date._Year = Year;
        date._Day = day;
        int remining = AddingDays + NumberOfDaysFromTheBeginingOfTheYear(Year, month, day);
        short monthDays = 0;
        date._Month = 1;
        while (true)
        {
            monthDays = NumberOfDaysInAMounth(date._Year, date._Month);

            if (remining > monthDays)
            {
                remining -= monthDays;
                date._Month++;

                if (date._Month > 12)
                {
                    date._Month = 1;
                    date._Year++;
                }

            }
            else
            {
                date._Day = remining;
                break;
            }
        }

        return date;


    }
    void AddDays(int AddingDays)
    {
        *this = AddDays(_Year, _Month, _Day, AddingDays);
    }

    //18
    void ReadDate()
    {
        cout << "Plaes enter a Day   : ";
        cin >> _Day;
        cout << "Plaes enter a month   : ";
        cin >> _Month;
        cout << "Plaes enter a Year   : ";
        cin >> _Year;
    }

    //19
    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year < Date2._Year) ? true
            : (Date1._Year > Date2._Year) ? false
            : (Date1._Month < Date2._Month) ? true
            : (Date1._Month > Date2._Month) ? false
            : (Date1._Day < Date2._Day);
    }
    bool IsDateBeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    //20
    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
    }
    bool IsDateEqualDate2(clsDate Date2)
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    //21
    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }
    bool IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    //22
    static short CompareDates(clsDate date1, clsDate date2)
    {
        if (IsDate1EqualDate2(date1, date2))
            return 0;
        else if (IsDate1BeforeDate2(date1, date2))
            return -1;
        else
            return 1;

    }
    short CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }

    //23
    static bool IsLastDay(clsDate date)
    {
        return NumberOfDaysInAMounth(date._Year, date._Month) == date._Day;
    }
    bool IsLastDay()
    {
        return IsLastDay(*this);
    }

    //24
    static bool IsFirstDay(clsDate date)
    {
        return date._Day == 1;
    }
    bool IsFirstDay()
    {
        return IsLastDay(*this);
    }

    //25
    static bool IsLastMonth(short month)
    {
        return month == 12;
    }
    bool IsLastMonth()
    {
        return IsLastMonth(_Month);
    }

    //26
    static bool IsFirstMonth(short month)
    {
        return month == 1;
    }
    bool IsFirstMonth()
    {
        return IsFirstMonth(_Month);
    }

    //27
    static clsDate AddOneDay(clsDate& date)
    {
        if (IsLastDay(date))
        {
            if (IsLastMonth(date._Month))
            {
                date._Month = 1;
                date._Day = 1;
                date._Year++;
            }
            else
            {
                date._Day = 1;
                date._Month++;
            }
        }
        else
            date._Day++;
        return date;
    }
    void AddOneDay()
    {
        AddOneDay(*this);
    }

    //28
    static void Print(clsDate date)
    {
        cout << DateToString(date) << endl;
    }
    void Print()
    {
        Print(*this);
    }

    //29
    static void Swab(clsDate& date1, clsDate& date2)
    {
        clsDate Temp = date1;
        date1 = date2;
        date2 = Temp;
    }
    void Swab(clsDate& date2)
    {
        Swab(*this, date2);
    }

    //30
    static short CaculateDiffrenceInDays(clsDate date1, clsDate date2, bool EndDay = false)
    {
        int days = 0;
        short swabValue = 1;
        if (IsDate1EqualDate2(date1, date2))
            return 0;
        else if (!IsDate1BeforeDate2(date1, date2))
        {
            Swab(date1, date2);
            swabValue = -1;
        }
        while (IsDate1BeforeDate2(date1, date2))
        {
            days++;
            date1 = AddOneDay(date1);
        }


        return  EndDay ? ++days * swabValue : days * swabValue;

    }
    short CaculateDiffrenceInDays(clsDate date2, bool EndDay = false)
    {
        return CaculateDiffrenceInDays(*this, date2, EndDay);
    }

    //31
    static void CheckDaysInMonth(clsDate& date)
    {
        short NumberOfDaysICurrentMonth = NumberOfDaysInAMounth(date._Year, date._Month);
        if (date._Day > NumberOfDaysICurrentMonth)
        {
            date._Day = NumberOfDaysICurrentMonth;
        }

    }
    void CheckDaysInMonth()
    {
        CheckDaysInMonth(*this);
    }

    //32
    void SetSystemDate()
    {
        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);

        _Year = now.tm_year + 1900;
        _Month = now.tm_mon + 1;
        _Day = now.tm_mday;

    }

    //33
    static clsDate IncreaseDateBy_x_Days(clsDate& date, short Days)
    {
        while (Days > 0)
        {
            date = AddOneDay(date);
            Days--;
        }
        return date;
    }
    void IncreaseDateBy_x_Days(short Days)
    {
        IncreaseDateBy_x_Days(*this, Days);
    }

    //34
    static clsDate IncreaseDateBy_One_Week(clsDate& date)
    {
        short Days = 7;
        date = IncreaseDateBy_x_Days(date, Days);
        return date;
    }
    void IncreaseDateBy_One_Week()
    {
        IncreaseDateBy_One_Week(*this);
    }

    //35
    static clsDate IncreaseDateBy_x_Weeks(clsDate& date, short Weeks)
    {
        while (Weeks > 0)
        {
            date = IncreaseDateBy_One_Week(date);
            Weeks--;
        }
        return date;
    }
    void IncreaseDateBy_x_Weeks(short Weeks)
    {
        IncreaseDateBy_x_Weeks(*this, Weeks);
    }

    //36
    static clsDate IncreaseDateBy_One_Month(clsDate& date)
    {
        date._Month++;
        if (date._Month > 12)
        {
            date._Month = 1;
            date._Year++;
        }

        CheckDaysInMonth(date);
        return date;
    }
    void IncreaseDateBy_One_Month()
    {
        IncreaseDateBy_One_Month(*this);
    }

    //37
    static clsDate IncreaseDateBy_x_Months(clsDate& date, short months)
    {
        while (months > 0)
        {
            date = IncreaseDateBy_One_Month(date);
            months--;
        }
        return date;
    }
    void IncreaseDateBy_x_Months(short month)
    {
        IncreaseDateBy_x_Months(*this, month);
    }

    //38
    static clsDate IncreaseDateBy_One_Year(clsDate& date)
    {
        date._Year++;
        CheckDaysInMonth(date);
        return date;
    }
    void IncreaseDateBy_One_Year()
    {
        IncreaseDateBy_One_Year(*this);
    }

    //39
    static clsDate IncreaseDateBy_x_Years(clsDate& date, short Years)
    {
        while (Years > 0)
        {
            date = IncreaseDateBy_One_Year(date);
            Years--;
        }
        return date;
    }
    void IncreaseDateBy_x_Years(short Years)
    {
        IncreaseDateBy_x_Years(*this, Years);
    }

    //40
    static clsDate IncreaseDateBy_x_Years_Faster(clsDate& date, short Years)
    {
        date._Year += Years;
        CheckDaysInMonth(date);
        return date;
    }
    void IncreaseDateBy_x_Years_Faster(short Years)
    {
        IncreaseDateBy_x_Years_Faster(*this, Years);
    }

    //41
    static clsDate IncreaseDateBy_One_Decade(clsDate& date)
    {
        date._Year += 10;
        CheckDaysInMonth(date);
        return date;
    }
    void IncreaseDateBy_One_Decade()
    {
        IncreaseDateBy_One_Decade(*this);
    }

    //42
    static clsDate IncreaseDateBy_x_Decades(clsDate& date, short Decade)
    {
        while (Decade > 0)
        {
            date = IncreaseDateBy_One_Decade(date);
            Decade--;
        }
        return date;
    }
    void IncreaseDateBy_x_Decades(short Decade)
    {
        IncreaseDateBy_x_Decades(*this, Decade);
    }

    //43
    static clsDate IncreaseDateBy_One_Century(clsDate& date)
    {
        date._Year += 100;
        CheckDaysInMonth(date);
        return date;
    }
    void IncreaseDateBy_One_Century()
    {
        IncreaseDateBy_One_Century(*this);
    }

    //44
    static clsDate IncreaseDateBy_One_Millennium(clsDate& date)
    {
        date._Year += 1000;
        CheckDaysInMonth(date);
        return date;
    }
    void IncreaseDateBy_One_Millennium()
    {
        IncreaseDateBy_One_Millennium(*this);
    }


    //45
    static clsDate DecreaseDate1Day(clsDate& date)
    {

        if (IsFirstDay(date))
        {

            if (IsFirstMonth(date._Month))
            {
                date._Month = 12;
                date._Year--;
            }
            else
            {
                date._Month--;
            }
            date._Day = NumberOfDaysInAMounth(date._Year, date._Month);
        }

        else
            date._Day--;

        return date;
    }
    void DecreaseDate1Day1()
    {
        DecreaseDate1Day(*this);
    }

    //46
    static clsDate DecreaseDateBy_x_Days(clsDate& date, short Days)
    {
        for (short i = 1; i <= Days; i++)
        {
            date = DecreaseDate1Day(date);
        }
        return date;
    }
    void DecreaseDateBy_x_Days(short Days)
    {
        DecreaseDateBy_x_Days(*this, Days);
    }

    //47
    static clsDate DecreaseDateBy_One_Week(clsDate& date)
    {
        short Days = 7;
        date = DecreaseDateBy_x_Days(date, Days);
        return date;
    }
    void  DecreaseDateBy_One_Week()
    {
        DecreaseDateBy_One_Week(*this);
    }

    //48
    static clsDate DecreaseDateBy_x_Weeks(clsDate& date, short Weeks)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            date = DecreaseDateBy_One_Week(date);
        }
        return date;
    }
    void DecreaseDateBy_x_Weeks(short Weeks)
    {
        DecreaseDateBy_x_Weeks(*this, Weeks);
    }

    //49
    static clsDate DecreaseDateBy_One_Month(clsDate& date)
    {
        date._Month--;
        if (date._Month < 1)
        {
            date._Month = 1;
            date._Year--;
        }
        CheckDaysInMonth(date);

        return date;
    }
    void DecreaseDateBy_One_Month()
    {
        DecreaseDateBy_One_Month(*this);
    }

    //50
    static clsDate DecreaseDateBy_x_Months(clsDate& date, short months)
    {
        for (short i = 1; i <= months; i++)
        {
            date = DecreaseDateBy_One_Month(date);
        }
        return date;
    }
    void DecreaseDateBy_x_Months(short months)
    {
        DecreaseDateBy_x_Months(*this, months);
    }

    //51
    static clsDate DecreaseDateBy_One_Year(clsDate& date)
    {
        date._Year--;
        CheckDaysInMonth(date);
        return date;
    }
    void DecreaseDateBy_One_Year()
    {
        DecreaseDateBy_One_Year(*this);
    }

    //52
    static clsDate DecreaseDateBy_x_Years(clsDate& date, short Years)
    {
        for (short i = 1; i <= Years; i++)
        {
            date = DecreaseDateBy_One_Year(date);
        }
        return date;
    }
    void  DecreaseDateBy_x_Years(short Years)
    {
        DecreaseDateBy_x_Years(*this, Years);
    }

    //53
    static clsDate DecreaseDateBy_One_Decade(clsDate& date)
    {
        date._Year -= 10;
        CheckDaysInMonth(date);
        return date;
    }
    void DecreaseDateBy_One_Decade()
    {
        DecreaseDateBy_One_Decade(*this);
    }

    //54
    static clsDate DecreaseDateBy_x_Decades(clsDate& date, short Decade)
    {
        for (short i = 1; i <= Decade; i++)
        {
            date = DecreaseDateBy_One_Decade(date);
        }
        return date;
    }
    void DecreaseDateBy_x_Decades(short Decade)
    {
        DecreaseDateBy_x_Decades(*this, Decade);
    }

    //55
    static clsDate DecreaseDateBy_One_Century(clsDate& date)
    {
        date._Year -= 100;
        CheckDaysInMonth(date);
        return date;
    }
    void DecreaseDateBy_One_Century()
    {
        DecreaseDateBy_One_Century(*this);
    }

    //56
    static clsDate DecreaseDateBy_One_Millennium(clsDate& date)
    {
        date._Year -= 1000;
        CheckDaysInMonth(date);
        return date;
    }
    void DecreaseDateBy_One_Millennium()
    {
        DecreaseDateBy_One_Millennium(*this);
    }

    //57
    static void PrintDayAndDate(clsDate date)
    {
        short cDay = DayOrder(date);
        string dayName = DayName(cDay);
        cout << dayName << " , [ " << DateToString(date) << " ]\n";
    }
    void PrintDayAndDate()
    {
        PrintDayAndDate(*this);
    }

    //58
    static bool IsEndOfWeek(clsDate date)
    {
        return (DayOrder(date) == 6) ? true : false;
    }
    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    //59
    static bool IsWeekEnd(clsDate date)
    {
        short cDay = DayOrder(date);
        return (cDay == 5 || cDay == 6) ? true : false;
    }
    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    //60
    static bool IsBusinessDay(clsDate date)
    {
        return !IsWeekEnd(date);
    }
    bool IsBusinessDay()
    {
        return  IsBusinessDay(*this);
    }

    //61
    static short DaysUntilTheEndOfWeek(clsDate date)
    {
        return 6 - DayOrder(date);
    }
    short DaysUntilTheEndOfWee()
    {
        return  DaysUntilTheEndOfWeek(*this);
    }

    //62
    static short DaysUntilTheEndOfMonth(clsDate Date)
    {
        return NumberOfDaysInAMounth(Date._Year, Date._Month) - Date._Day + 1;
    }
    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    //63
    static short DaysUntilTheEndOfYear(clsDate Date)
    {
        return NumberOfDaysInAYear(Date._Year) - NumberOfDaysFromTheBeginingOfTheYear(Date) + 1;
    }
    short DaysUntilTheEndOfYear()
    {
        return  DaysUntilTheEndOfYear(*this);
    }

    //64
    static short VacationDays(clsDate dateS, clsDate dateE)
    {
        short Vacation = 0;
        while (!IsDate1EqualDate2(dateS, dateE))
        {
            if (IsBusinessDay(dateS))
            {
                Vacation++;
            }
            dateS = AddOneDay(dateS);
        }
        return Vacation;
    }
    short VacationDays(clsDate dateE)
    {
        return VacationDays(*this, dateE);
    }

    //65
    static clsDate ReturnVacationDate(short vDays, clsDate DateFrom)
    {
        while (vDays > 0)
        {
            if (IsBusinessDay(DateFrom))
            {
                vDays--;
            }
            DateFrom = AddOneDay(DateFrom);
        }
        return DateFrom;
    }
    clsDate ReturnVacationDate(short vDays)
    {
        return ReturnVacationDate(vDays, *this);
    }

    //66
    static bool IsValide(clsDate date)
    {
        return !(date._Day > NumberOfDaysInAMounth(date.Year, date.Month) || date._Day < 1 || date._Month > 12 || date._Month < 1);

    }
    bool IsValide()
    {
        return  IsValide(*this);
    }

    //67
    static string DateToString(clsDate date)
    {
        return to_string(date._Day) + "/" + to_string(date._Month) + "/" + to_string(date._Year);

    }
    string DateToString()
    {
        return DateToString(*this);
    }

    //68
    static string GetDateTime()
    {
        return DateToString(clsDate()) + " - " + clsTime::Time();
    }




};

