#include "utils.h"

int foolSort(int* arr, int count) // O(N^2)
{
	int i = 0;
	myTypeTime start, end;

	start = std::chrono::system_clock::now();
	while (i < count - 1)
	{
		if (*(arr + i) > * (arr + i + 1))
		{
			int tmp = *(arr + i);
			*(arr + i) = *(arr + i + 1);
			*(arr + i + 1) = tmp;
			i = 0;
			continue;
		}
		i++;
	}

	end = std::chrono::system_clock::now();
	return (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

int wrongBubleSort(int* arr, int count)
{
	myTypeTime start, end;
	start = std::chrono::system_clock::now();
	for (int i = count; i > 0; i--)
		for (int j = 0; j < count - 1; j++)
		{
			if (*(arr + j) > * (arr + j + 1))
			{
				int tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
			}
		}

	end = std::chrono::system_clock::now();
	return (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

int bubleSort(int* arr, int count)
{
	myTypeTime start, end;
	start = std::chrono::system_clock::now();
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count - i - 1; j++)
		{
			if (*(arr + j) > * (arr + j + 1))
			{
				int tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
			}
		}

	end = std::chrono::system_clock::now();
	return (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

//int monkeySort(int* arr, int count)
//{
//	myTypeTime start, end;
//	start = std::chrono::system_clock::now();
//	int i = 0;
//	while (!correctMonkey(arr, count))
//	{
//		if (*(arr + i) > * (arr + i + 1))
//		{
//
//			i = 0;
//			continue;
//		}
//		i++;
//		if (i == count)
//			break;
//	}
//	end = std::chrono::system_clock::now();
//	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//}
//
//int correctMonkey(int* arr, int count)
//{
//	bool * arrFree = new bool [count];
//	int tmp = 0;
//	for(int i = 0; i < 0; i++)
//		tmp = 
//	return 0;
//}

int correct(int* arr, int size) {
	while (size-- > 0)
		if (arr[size - 1] > arr[size])
			return 0;
	return 1;
}

void shuffle(int* arr, int size) {
	for (int i = 0; i < size; ++i)
		std::swap(arr[i], arr[(rand() % size)]);
}

int bogoSort(int* arr, int size) {
	myTypeTime start, end;
	start = std::chrono::system_clock::now();
	
	while (!correct(arr, size))
		shuffle(arr, size);

	end = std::chrono::system_clock::now();
	return (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
