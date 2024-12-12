#include <iostream>
#include <ctime>
#include "function.h"
using namespace std;

int main()
{
	srand(time(0));
	const int SIZE = 10;
	int arr[SIZE];
	Init(arr, SIZE);
	Print(arr, SIZE);
	int s = 0, p = 1;
	Sum(arr, SIZE, s, p);
	cout << "\nSum of elements: " << s << "\n";
	cout << "Product of elements: " << p << "\n\n";

	const int ROW = 5, COLUMN = 4;
	int arr2[ROW][COLUMN];
	Init(arr2, ROW);
	Print(arr2, ROW);
	int even = 0, odd = 0;
	double average = Average(arr2, ROW, even, odd);
	cout << "\nAverage of elements: " << average;
	cout << "\nQuantity of even elements: " << even;
	cout << "\nQuantity of odd elements: " << odd;

	int *ptr = nullptr;
	int size, value, index;
	cout << "\nEnter a quantity of elements: ";
	cin >> size;
	Allocate(ptr, size);
	Init(ptr, size);
	Print(ptr, size);

	cout << "\nEnter a value to add: ";
	cin >> value;
	Add(ptr, size, value);
	Print(ptr, size);

	cout << "\nEnter an index to insert: ";
	cin >> index;
	InsertByIndex(ptr, size, value, index);
	Print(ptr, size);

	cout << "\nEnter an index to remove: ";
	cin >> index;
	RemoveByIndex(ptr, size, index);
	Print(ptr, size);
	Free(ptr);
	ptr = nullptr;

	return 0;
}