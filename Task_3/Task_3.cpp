// Task 3.Create a function that allows you to delete from an array elements from n to m.
// After elements are deleted, the array must be truncated.
//

#include <iostream>
using namespace std;

int* CutArray(int* arr, int& size);//Delete from an array elements from n to m
void PrintArray(int* arr, int& size);//Print function
void GenerateArray(int* arr, int& size);//Generat function

int main()
{
	srand(time(NULL));

	int size;
	cout << "\n\tEnter size => ";	cin >> size;

	int* arr = new int[size];

	GenerateArray(arr, size);

	PrintArray(arr, size);

	arr = CutArray(arr, size);//Rewriting old array

	PrintArray(arr, size);
}

int* CutArray(int* arr, int& size)//Delete from an array elements from n to m
{
	cout << "\n\tEnter start element to delete => ";
	int n;
	cin >> n;

	cout << "\n\tEnter finish element to delete => ";
	int m;
	cin >> m;
	
	size = size - (m - n);
	int* arr_new = new int[size];

	int j = 0;
	for (int i = 0; i < size + m - n; i++)
	{
		if ((i < n) || (i >= m))
		{
			arr_new[j] = arr[i];
			j++;
		}
	}
	delete[] arr;
	return arr_new;
}

void PrintArray(int* arr, int& size)//Print function
{
	cout << "\n\tArray: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void GenerateArray(int* arr, int& size)//Generat function
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}