//файл dbmsLib1.h
#pragma once
#ifndef _dbmsLib1_
#define _dbmsLib1_
#include <iostream>
#include <fstream>
#include <strstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;


//-----------------класс DBDate1----------------------------
  class DBDate1{
	private:
		int day; 
		int month; 
		int year;
		static const int arrDaysInMonths[13];
		friend string DateToStr(DBDate1& date);
		friend ostream& operator<<(ostream& out,DBDate1& date);
		//bool IsCorrectDate(int d, int m, int y);       ?????????????
	public:
		DBDate1(string date);//формат строки: dd.mm.yyyy
		DBDate1(int d,int m,int y);
		DBDate1():day(1),month(1),year(1){};//конструктор по умолчанию
		DBDate1(DBDate1& dat):day(dat.day),month(dat.month),year(dat.year){} //конструктор копировани€
		int GetDay();
		int GetMonth();
		int GetYear();
		bool IsLeapYear (int year); // год високосный?
		bool IsCorrectDate(int d, int m, int y);
		int GetDaysInMonth(int month,int year);// оличество дней в мес€це
		int DaysInCurYear();// оличество дней от начала года до текущей даты
		bool operator==(DBDate1& date);
		bool operator<(DBDate1& date); 
		bool operator>(DBDate1& date);
		bool operator<= (DBDate1& date);
		bool operator>= (DBDate1& date);
		bool operator!= (DBDate1& date);
		DBDate1& operator+=(int days);//ѕрибавл€ет к текущей дате days дней
		DBDate1& operator-=(int days);//¬ычитает из текущей даты days дней
		int operator-(DBDate1& date);// оличество дней между текущей датой и date
						//≈сли текуща€ дата > date, результат < 0.
  };

#endif //конец _dbmsLib1_