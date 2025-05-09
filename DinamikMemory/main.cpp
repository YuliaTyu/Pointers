#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int arr[], int& n, const int value);
int* Erase(int arr[], int& w, const int n);

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

	delete[] arr;
	//Memory leak

	
	int w;
	cout << "Введите номер элемента который нужно удалить"; cin >> w;
	arr = Erase(arr, n, w);
	Print(arr, n);
	
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
int* Erase(int arr[], int& w, const int n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	cout << endl;

	delete[] arr;
	arr = buffer;
	arr[n] = w;
	
	

	return arr;
	
}