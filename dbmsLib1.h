//���� dbmsLib1.h
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


//-----------------����� DBDate1----------------------------
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
		DBDate1(string date);//������ ������: dd.mm.yyyy
		DBDate1(int d,int m,int y);
		DBDate1():day(1),month(1),year(1){};//����������� �� ���������
		DBDate1(DBDate1& dat):day(dat.day),month(dat.month),year(dat.year){} //����������� �����������
		int GetDay();
		int GetMonth();
		int GetYear();
		bool IsLeapYear (int year); // ��� ����������?
		bool IsCorrectDate(int d, int m, int y);
		int GetDaysInMonth(int month,int year);//���������� ���� � ������
		int DaysInCurYear();//���������� ���� �� ������ ���� �� ������� ����
		bool operator==(DBDate1& date);
		bool operator<(DBDate1& date); 
		bool operator>(DBDate1& date);
		bool operator<= (DBDate1& date);
		bool operator>= (DBDate1& date);
		bool operator!= (DBDate1& date);
		DBDate1& operator+=(int days);//���������� � ������� ���� days ����
		DBDate1& operator-=(int days);//�������� �� ������� ���� days ����
		int operator-(DBDate1& date);//���������� ���� ����� ������� ����� � date
						//���� ������� ���� > date, ��������� < 0.
  };

#endif //����� _dbmsLib1_