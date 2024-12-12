#include <iostream>
using namespace std;

// Функция получает указатель на массив и его размер, и 
// заполняет массив случайными числами
void Init(int *const &ref, int size)
{
	for (int i = 0; i < size; i++)
	{
		ref[i] = rand() % 10 + 1;
	}
}

// Функция получает указатель на массив и его размер, и 
// выводит массив на экран
void Print(int *const &ref, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ref[i] << '\t';
	}
}

// Функция получает указатель на массив и его размер, и 
// возвращает сумму и произведение его элементов в двух 
// параметрах-ссылках
void Sum(int *ptr, int size, int &s, int &p)
{
	for (int i = 0; i < size; i++)
	{
		s += *(ptr + i);
		p *= ptr[i];
	}
}

// Функция получает указатель на двумерный массив и его размер, 
// и заполняет массив случайными числами
void Init(int ptr[][4], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ptr[i][j] = rand() % 50;
		}
	}
}

// Функция получает указатель на двумерный массив и его размер, 
// и выводит массив на экран
void Print(int(*ptr)[4], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << *(*(ptr + i) + j) << '\t';
		}
		cout << endl;
	}
}

// Функция получает указатель на двумерный массив и его размер, 
// и возвращает среднее арифметическое элементов массива, 
// а также количество чётных и нечётных элементов
double Average(int(*ptr)[4], int size, int &even, int &odd)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum += ptr[i][j];
			if (ptr[i][j] % 2 == 0)
				even++;
			else
				odd++;
		}
	}
	return sum / double(size * 4);
}

// функция создания динамического массива
void Allocate(int *& ptr, int size)
{
	ptr = new int[size];
}

// функция удаления динамического массива
void Free(int *&ptr)
{
	delete[] ptr;
}

// функция добавления элемента в конец массива
void Add(int *&ptr, int &size, int value)
{
	int *p = new int[++size];
	for (int i = 0; i < size - 1; i++)
		p[i] = ptr[i];
	p[size - 1] = value;
	delete[]ptr;
	ptr = p;
}

// функция вставки элемента по указанному индексу 
void InsertByIndex(int *&ptr, int &size, int value, int index)
{
	if (index < 0 || index > size - 1)
		return;

	int *p = new int[++size];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (index == i)
		{
			k = 1;
			p[i] = value;
		}
		else
			p[i] = ptr[i - k];
	}
	delete[]ptr;
	ptr = p;
}

// функция удаления элемента по указанному индексу
void RemoveByIndex(int *&ptr, int &size, int index)
{
	if (index < 0 || index > size - 1)
		return;

	int *p = new int[--size];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (index == i)
			k = 1;
		p[i] = ptr[i + k];
	}
	delete[]ptr;
	ptr = p;
}