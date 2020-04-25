#include "utils.h"

int foolSort(int * arr, int count) // O(N^2)
{
	int i = 0;
	myTypeTime start, end;
	
	start = std::chrono::system_clock::now();
	while(i<count-1)
	{
		if (*(arr+i) > * (arr + i+1))
		{
			int tmp = *(arr + i);
			*(arr + i) = *(arr + i +1);
			*(arr + i +1) = tmp;
			i = 0;
			continue;
		}
		i++;
	}

	end = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

int wrongBubleSort(int* arr, int count)
{
	myTypeTime start, end;
	start = std::chrono::system_clock::now();
	for(int i=count; i > 0; i--)
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
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
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
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
