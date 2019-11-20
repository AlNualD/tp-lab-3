#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <time.h>
using namespace std;
class DateTime
{
public:
	DateTime(int day, int mon, int year)
	{
		timeStruct = { 0,0,0,day,mon-1,year - 1900 };
		mktime(&timeStruct);
	}
	DateTime()
	{
		tm* LocTim = new tm;
		time_t t;
		t = time(NULL);
		LocTim = localtime(&t);
		timeStruct = *LocTim;
		delete LocTim;
	}


	string getToday();
	string getYesterday(); // ����������� ���� ���������� ��� � ���� ������.
	string getTomorrow(); // -����������� ���� ����������� ��� � ���� ������.
	string getFuture(unsigned int N); // -����������� ���� ����� N ���� � �������;
	string getPast(unsigned int N); // ����������� ���� ����� N ���� � �������;
	int getDifference(DateTime&); //��� ������� �������(� ����) ����� ����� ������

private:
	tm timeStruct;
	bool visYear(int y);
	int daysInMon(int m, bool y);
	string retDate(tm datetm);
	tm retTM(DateTime);
	bool sameDate(tm date2);
};
