// Task 1. Create a function that allows you to add a block elements at the end of the array.
//

#include <iostream>
using namespace std;

int* AddElementsToTheEnd(int* arr, int& size);//Add a elements at the end of the array
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

	arr = AddElementsToTheEnd(arr, size);//Rewriting old array

	PrintArray(arr, size);
}

int* AddElementsToTheEnd(int* arr, int& size)//Add a elements at the end of the array
{
	cout << "\n\tEnter the number of new elements => ";
	int elements_size;
	cin >> elements_size;

	size += elements_size;//New size
	int* arr_new = new int[size];//New array

	for (int i = 0; i < size - elements_size; i++)//Fills the new array with the old one
	{
		arr_new[i] = arr[i];
	}

	for (int i = size - elements_size; i < size; i++)//Entering new array elements
	{
		cout << "\n\tEnter new element => ";
		cin >> arr_new[i];
	}

	delete[] arr;//Removing the old array
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