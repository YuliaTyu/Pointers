﻿#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n---------------------------------------\n";

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* Push_back(int arr[], int& n, const int value);
int* Push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value, int index);
int* Pop_back(int arr[], int& n);

int** push_row_back(int** arr, int& rows, const int cols);//добавляем строку в массив

//#define DINAMIC_MEMORY_1

void main()
{
	setlocale(LC_ALL, "");

#ifdef DINAMIC_MEMORY_1


	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;


	int value;
	cout << "Введите добавляемое значение"; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);
	
	cout << "Введите добавляемое значение"; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);
	
	int index;
	cout << "Введите индекс добавляемого значение"; cin >> index;
	cout << "Введите значение добавляемого значение"; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	Print(arr = Pop_back(arr, n), n);// удален последний элемент массива

	delete[] arr;

#endif // DINAMIC_MEMORY_1


	int rows;
	int cols;
	cout << "Введите кол-во строк"; cin >> rows;
	cout << "Введите кол-во элементов строки"; cin >> cols;

	//создаем массив указателей
	int** arr = new int* [rows];

	//выделяем память под строки двумерного динамич массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);


	
	//очистить память
	for (int i = 0; i < rows; i++)// сначала удаляем строки
	{
		delete[] arr[i];
	}
	delete[] arr;// удаляем массив укзателей


}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	//заполнем рандомом и выводим на экран
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << delimeter;
	cout << endl;
}

int* Push_back(int arr[], int& n, const int value)
{
	//переопределить память - создаем буфферный массив нужного массива
	int* buffer = new int[n + 1];

	//копируем все содежимое исходного массива в буфферный массив
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//удаляем исходный массив 
	delete[] arr;

	//подменяем адрес в указателе arr адресом нового массива

	arr = buffer;

	//только после этого в конце массива появляется элемент, в которое можно сохранить добавляемое значение
	arr[n] = value;

	//после того как в массив дбавился элемент количество его элементов увеличивается на 1
	n++;
	
	return arr;
}
int* Push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* insert(int arr[], int& n, const int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];
	
	delete[] arr;

	buffer[index] = value;
	n++;
	return buffer;
}


int* Pop_back(int arr[], int& n)
{
	cout << arr << endl;
	int* buffer = new int[--n];//памать выделится в первую очередь из-за --
	for (int i = 0; i < n; i++)buffer[i] = arr[i];//копируем массив в буффер
	delete[] arr;//удаляем исходный
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//создаем буффур указателей нужного размера
	int** buffer = new int* [rows+1];

	//копируем адреса строк в буфферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	// удаляем массив укзателей	
	delete[] arr;

	//создаем добавляемую строку и записываем ее адрес в массив указателей 
	buffer[rows] = new int[cols] {};

	//при добавлении в массив строки количество его строк увеличивается на 1
	rows++;

	//возвращаем новый массив на место вызова
	return buffer;

}

