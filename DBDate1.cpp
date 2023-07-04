#include "dbmsLib1.h"

const int DBDate1::arrDaysInMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

DBDate1::DBDate1(string date){
	int d = 10*(date[0]-'0')+(date[1]-'0');
	int m = 10*(date[3]-'0')+(date[4]-'0');
	int y = 1000*(date[6]-'0')+100*(date[7]-'0')+10*(date[8]-'0')+(date[9]-'0');
	if (IsCorrectDate(d, m, y) == 1){
		day = d;
		month = m;
		year = y;
	} else {
		cout << "Некорректная дата" << endl;
		day = 1;
		month = 1;
		year = 1;
	}
}

bool DBDate1::IsCorrectDate(int d, int m, int y){
	if ((y < 1) || (m < 0 || m >12) || (d < 0 || d > GetDaysInMonth(m, y))){
					return false;
	}
	return true;
}

DBDate1::DBDate1(int d,int m,int y){
	if (IsCorrectDate(d, m, y) == 1){
		day = d;
		month = m;
		year = y;
	} else {
		cout << "Некорректная дата" << endl;
		day = 1;
		month = 1;
		year = 1;
	}
}

int DBDate1::GetDay(){
	return day;
}

int DBDate1::GetMonth(){
	return month;
}

int DBDate1::GetYear(){
	return year;
}

bool DBDate1::IsLeapYear(int year){
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) ){
		return true;
	}
	return false;
}

int DBDate1::GetDaysInMonth(int month,int year){
	int day;
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	day = days[month];
	if (month == 2 && IsLeapYear(year)){
		day += 1;
	}
	return day;
}

int DBDate1::DaysInCurYear(){
	return 0;
}

bool DBDate1::operator==(DBDate1& date){
	return year == date.year && month == date.month && day == date.day;
}

bool DBDate1::operator<(DBDate1& date){
	while (year <date.year || (year == date.year&&month < date.month) ||
(year == date.year && month == date.month && day < date.day)){
	return true;
	}
	return false;
} 

bool DBDate1::operator>(DBDate1& date){
	if (year > date.year){
		return true;
	} else if (year == date.year){
		if (month > date.month){
			return true;
		} else if (month == date.month){
			if (day > date.day){
				return true;
			}
		}
	}
	return false;
}

bool DBDate1::operator<= (DBDate1& date){
	if(year <= date.year)
		return true;
	else if(year == date.year && month <= date.month)
		return true;
	else if(year == date.year && month == date.month && day <= date.day)
		return true;
	return false;
}

bool DBDate1::operator>= (DBDate1& date){
	if(year >= date.year)
		return true;
	else if(year == date.year && month >= date.month)
		return true;
	else if(year == date.year && month == date.month && day >= date.day)
		return true;
	return false;
}

bool DBDate1::operator!= (DBDate1& date){
	if (year != date.year || month != date.month || day != date.day){
		return true;
	}
	return false;
}

DBDate1& DBDate1::operator+=(int days){
	/*days += day;
	while (true){
		days -= GetDaysInMonth(month, year);
		if (days <= 0){
			day = days + GetDaysInMonth(month, year);
			break;
		}
		++month;
		if (month == 13){
			month = 1;
			++year;
		}
	}
	return *this;*/
	day += days;
	while(day > GetDaysInMonth(month, year)){
		day -= GetDaysInMonth(month, year);
		++month;
		if(month == 13){
			++year;
			month = 1;
		}
	}
	return *this;
}

DBDate1& DBDate1::operator-=(int days){
	day -= days;
	while(day < 0){
		--month;
		if (month == 0){
			month = 12;
			year--;
		}
		day += GetDaysInMonth(month, year);
	}
	if (day == 0){
		month -= 1;
		if (month == 0){
			month = 12;
			year--;
		}
		day = GetDaysInMonth(month, year);
	}
	return *this;
}

int DBDate1::operator-(DBDate1& date){
	/*DBDate1 tmp(date);
	int cnt = 0;
	if (tmp <= *this){
		while (tmp != *this){
			tmp +=1;
			++cnt;
		}
	} else {
		while (tmp != *this){
			tmp -=1;
			--cnt;
		}
	}
	return cnt;*/
	DBDate1 max = *this;
	DBDate1 min = date;
	int flag = 1;
	int n = 0;
	if (min > max){
		max = date;
		min = *this;
		flag = -1;
	}
	while (min < max){
		min+=1;
		n++;
	}
	return n * flag;
}


/*string DateToStr(DBDate1& date){
	string s = "";
	return s;
	//как снизу только все поля перевести в одну строку
}*/

ostream& operator<<(ostream& out,DBDate1& date){
	out << date.day << "." << date.month << "." << date.year;
	return out;
}