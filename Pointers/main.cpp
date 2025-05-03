#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Pointers" << endl;
	int a = 2;
	int* pa = &a; //объявление указателя
	cout << a << endl;  //вывод переменной на экран
	cout << &a << endl; //амперсант - взятие адреса переменной а при выводе
	cout << pa << endl; //вывод адреса пременной а, хранящегося в указателе ра
	cout << *pa << endl;//взятие значения а из указателя
}