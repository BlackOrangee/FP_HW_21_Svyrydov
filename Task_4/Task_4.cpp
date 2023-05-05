// Task 4.The array is given: А[M] (M is entered from the keyboard).
// The user enters data into the array, and also uses the menu to decide what to delete from the array to choose from : 
// [■] Paired elements
// [■] Odd elements
// [■] Maximum element
// [■] Minimal element
// [■] Elements greater than the median of the array
// [■] Elements smaller than the median of the array
//

#include <iostream>
using namespace std;

void PrintArray(int* arr, int& size);//Print function
void GenerateArray(int* arr, int& size);//Generat function
int* MemCleaner(int* arr_new, int& size);
int* PairedElements(int* arr, int& size);
int* OddElements(int* arr, int& size);
void MaximumElement(int* arr, int& size);
void MinimalElement(int* arr, int& size);
void GreaterMedianElements(int* arr, int& size);
void SmallerMedianElements(int* arr, int& size);

int main()
{
	srand(time(NULL));

	int size;
	cout << "\n\tEnter size => ";	cin >> size;

	int* arr = new int[size];

	GenerateArray(arr, size);

	while (true)
	{
		PrintArray(arr, size);

		int menu = 0;

		cout << "\n\n\tDelete from array\n\n\t1 -- Paired elements\n\t2 -- Odd elements\n\t3 -- Maximum element\n\t4 -- Minimal element\n\t5 -- Elements greater than the median of the array\n\t6 -- Elements smaller than the median of the array\n\t";
		cin >> menu;

		switch (menu)
		{
		case 1://Paired elements
			arr = PairedElements(arr, size);
			break;
		case 2://Odd elements
			arr = OddElements(arr, size);
			break;
		case 3://Maximum element
			MaximumElement(arr, size);
			arr = MemCleaner(arr, size);
			break;
		case 4://Minimal element
			MinimalElement(arr, size);
			arr = MemCleaner(arr, size);
			break;
		case 5://Elements greater than the median of the array
			GreaterMedianElements(arr, size);
			arr = MemCleaner(arr, size);
			break;
		case 6://Elements smaller than the median of the array
			SmallerMedianElements(arr, size);
			arr = MemCleaner(arr, size);
			break;
		default:
			break;
		}
	}
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
		arr[i] = rand() % 50;
	}
}

int* MemCleaner(int* arr, int& size)
{
	int* arr_new = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr_new[i] = arr[i];
	}
	delete[] arr;
	return arr_new;
}

int* PairedElements(int* arr, int& size)
{
	int* arr_new = new int[size];
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (i % 2)
		{
			arr_new[j] = arr[i];
			j++;
		}
	}
	size = j;
	delete[] arr;
	arr_new = MemCleaner(arr_new, size);
	return arr_new;
}

int* OddElements(int* arr, int& size)
{
	int* arr_new = new int[size];
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (!(i % 2))
		{
			arr_new[j] = arr[i];
			j++;
		}
	}
	size = j;
	delete[] arr;
	arr_new = MemCleaner(arr_new, size);
	return arr_new;
}

void MaximumElement(int* arr, int& size)
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == max)
		{
			for (int j = i; j < size - 1; j++)
			{
				swap(arr[j], arr[j + 1]);
			}
			size -= 1;
			i--;
		}
	}
}

void MinimalElement(int* arr, int& size)
{
	int min = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == min)
		{
			for (int j = i; j < size - 1; j++)
			{
				swap(arr[j], arr[j + 1]);
			}
			size -= 1;
			i--;
		}
	}
}

void GreaterMedianElements(int* arr, int& size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	sum /= size;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > sum)
		{
			for (int j = i; j < size - 1; ++j)
			{
				swap(arr[j], arr[j + 1]);
			}
			size -= 1;
			i--;
		}
	}
}

void SmallerMedianElements(int* arr, int& size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	sum /= size;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < sum)
		{
			for (int j = i; j < size - 1; j++)
			{
				swap(arr[j], arr[j + 1]);
			}
			size -= 1;
			i--;
		}
	}
}
