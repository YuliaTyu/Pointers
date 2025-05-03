#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение"; cin >> value;

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
	Print(arr, n);


	delete[] arr;
	//Memory leak
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