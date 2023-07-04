#include <iostream>
#include <iomanip>
#include "dbmsLib_v1_1.h"
#include "dbmsLib1.h"

using namespace std;
int menu(){
	cout<<"============Разработка и тестирование класса DBDate1 ===================\n";
	cout<<"\t1 - Создание объектов DBDate1 и проверка конструкторов\n";
	cout<<"\t2 - Перегрузка и тестирование логических операторов сравнения\n";
	cout<<"\t3 - Перегрузка и тестирование оператора DBDate1& operator+=(int days)\n"; 
	cout<<"\t4 - Перегрузка и тестирование оператора DBDate1& operator-=(int days)\n"; 
	cout<<"\t5 - Перегрузка и тестирование оператора int operator-(DBD1ate& date)\n"; 
	cout<<"\t8 - Тестирование\n";
	cout<<"\t10 - Выход\n";
	int choice;
	cout<<"Выберите действие\n";
	cin>>choice;
	while(cin.fail()){
		cout<<"Ошибка ввода. Повторите ввод\n";
		cin.clear();
		cin.ignore(10,'\n');
		cin>>choice;
		}
	return choice;
}

//-----------------------------------------------------------------

void testing(){
	DBDate1 obj1("28.02.2023");
	DBDate1 obj2("28.02.2023");
	//DBDate1 obj3(01, 03, 2023);
	cout << "obj1 = " << obj1 << endl;
	cout << "obj2 = " << obj2 << endl;
	cout << obj1 - obj2 << endl;
	cout << "(obj1 >= obj2) = " << (obj1 >= obj2) << endl;
	cout<<endl;
}

/*void test1(){
}

void test2(){
}

void test3(){
}

void test4(){
}

void test5(){
}*/

//=================================================
int main(){
	system("chcp 1251>nul");
	while(true){
		switch(menu()){
		case 1:
			//test1();
			break;
		case 2: //Печать таблицы БД (screenWidth-ширина экрана)
			//test2();
			break;
		case 3: 
			//test3();
			break;
		case 4: 
			//test4();
			break;
		case 5:
			//test5();
			break;
		case 8:
			testing();
			break;
		case 10: 
			return 0;//завершение работы
		default:
			cout<<"Недопустимое действие. Повторите выбор\n"; 
			break;
		}
	}
	return 0;
}