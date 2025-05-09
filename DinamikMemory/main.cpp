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
	cout << "������� ������ �������: "; cin >> n;
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
	cout << "������� ����������� ��������"; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);

	delete[] arr;
	//Memory leak

	
	int w;
	cout << "������� ����� �������� ������� ����� �������"; cin >> w;
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
	//�������������� ������ - ������� ��������� ������ ������� �������
	int* buffer = new int[n + 1];

	//�������� ��� ��������� ��������� ������� � ��������� ������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//������� �������� ������ 
	delete[] arr;

	//��������� ����� � ��������� arr ������� ������ �������

	arr = buffer;

	//������ ����� ����� � ����� ������� ���������� �������, � ������� ����� ��������� ����������� ��������
	arr[n] = value;

	//����� ���� ��� � ������ �������� ������� ���������� ��� ��������� ������������� �� 1
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