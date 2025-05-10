#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int arr[], int& n, const int value);
int* Push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value, int index);
int* Pop_back(int arr[], int& n);

void main()
{
	setlocale(LC_ALL, "");
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

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
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