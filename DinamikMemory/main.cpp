#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n---------------------------------------\n";

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* Push_back(int arr[], int& n, const int value);//добавляет последний элемент массива
int* Push_front(int arr[], int& n, const int value);//добавляет нулевой элемент массива

int* insert(int arr[], int& n, const int value, int index);//добавляет значение по индексу

int* Pop_back(int arr[], int& n);//удаляет последний элемент массива(&размер по ссылке)
int* Pop_front(int arr[], int& n);//удаляет нулевой элемент массива

int* Erase(int arr[], int& n, const int index);//удаляет элемент массива по указанному индексу

int** push_row_back(int** arr, int& rows, const int cols);//добавляем строку в конец массива
int** push_row_front(int** arr, int& rows, int& cols);//добавляем строку в начало массива

int** push_col_back(int** arr, int& rows, int& cols);//добавляет столбец в конец массива
//int** push_col_front(int** arr, int& rows, int& cols);//добавляет столбец в начало массива

//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2


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

	cout << "Массив после уладения последнего элемента" << endl;
	Print(arr = Pop_back(arr, n), n);                            
	cout << "Массив после удаления нулевого элемента" << endl;
	Print(arr = Pop_front(arr, n), n);                           


	cout << "Введите индекс удаляемого значение"; cin >> index;
	cout << "Массив после удаления элемента по индексу" << endl;
	Print(arr = Erase(arr, n, index),n);
	


	delete[] arr;

#endif // DINAMIC_MEMORY_1

#ifdef DINAMIC_MEMORY_2


	int rows;
	int cols;
	cout << "Введите кол-во строк"; cin >> rows;
	cout << "Введите кол-во элементов строки"; cin >> cols;

	//(указатель ** на указатель)создаем массив указателей
	int** arr = new int* [rows];

	//выделяем память под строки двумерного динамич массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	
	cout << "Вывести двумерный динамический массив на экран используя арифметику указателей и оператор разыменования;)))))))) " << endl;
	int* prows;
	int* pcols;
	prows = &rows;
	pcols = &cols;
	cout << *prows << *pcols << endl;
	

	
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	
	arr = push_col_back(arr, rows, cols);//????????????
	Print(arr, rows, cols);

	





	//очистить память
	for (int i = 0; i < rows; i++)// сначала удаляем строки
	{
		delete[] arr[i];
	}
	delete[] arr;// удаляем массив укзателей

#endif // DINAMIC_MEMORY_2

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
	int* buffer = new int[n + 1];                 //переопределить память - создаем буфферный массив нужного массива
	for (int i = 0; i < n; i++)buffer[i] = arr[i];//копируем все содежимое исходного массива в буфферный массив
	delete[] arr;                                 //удаляем исходный массив 
	arr = buffer;                                 //подменяем адрес в указателе arr адресом нового массива
	arr[n] = value;                               //только после этого в конце массива появляется элемент, в которое можно сохранить добавляемое значение
	n++;                                          //после того как в массив дбавился элемент количество его элементов увеличивается на 1
	return arr;
}
int* Push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];                     //выделяем память нужного размера +1
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];//копируем в буффер
	delete[] arr;                                     //удаляем исходный массив
	buffer[0] = value;                                // добавляем значение в нулевой элемент!!!!!!!!!!!!
	n++;                                              // кол-во элементов в массиве увеличивается
	return buffer;
}

int* insert(int arr[], int& n, const int value, int index)
{
	int* buffer = new int[n + 1];                      //выделяем память нужного элемента   
	for (int i = 0; i < index; i++)buffer[i] = arr[i]; //копируем в буффер до индекса!
	
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];//копируем после индекса
	delete[] arr;                                         //удаляем исходный массив 
	buffer[index] = value;                                //в элемент добавляем значение по индексу!
	n++;
	return buffer;
}


int* Pop_back(int arr[], int& n)
{
	cout << arr << endl;
	int* buffer = new int[--n];                        //память выделится в первую очередь из-за --
	for (int i = 0; i < n; i++)buffer[i] = arr[i];     //копируем массив в буффер
	delete[] arr;                                      //удаляем исходный
	return buffer;
}
int* Pop_front(int arr[], int& n)
{
	cout << arr << endl;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];   
	delete[] arr;                                      
	arr = buffer;
	
	return buffer;
}


int* Erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return buffer;
}


int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows+1];                //создаем буфферный массив указателей нужного размера
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];//копируем адреса строк в буфферный массив указателей
	delete[] arr;                                    // удаляем массив укзателей	
	buffer[rows] = new int[cols] {};                 //создаем добавляемую строку и записываем ее адрес в массив указателей 
	rows++;                                          //при добавлении в массив строки количество его строк увеличивается на 1
	return buffer;                                   //возвращаем новый массив на место вызова
}
int** push_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows + 1];                   //создаем буффер указателей нужного размера
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];   //копируем адреса строк в буфферный массив указателей
	delete[] arr;                                         // удаляем массив укзателей	
	buffer[0] = new int[cols] {};                         //создаем добавляемую строку и записываем ее адрес в массив указателей
	rows++;                                               //при добавлении в массив строки количество его строк увеличивается на 1
	return buffer;                                        //возвращаем новый массив на место вызова
}
int** push_col_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];                  
	for (int i = 0; i < rows+1; i++)           
	{
		for (int j = 0; j < cols; j++)
		{                                            
			buffer[j] = arr[j];                       
		}
	}
	delete[] arr;                                      
	buffer[cols] = new int[cols+1] {};                   
	cols++;                                            
	return buffer;                                    
}
