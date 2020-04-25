#include <iostream>
#include <random>
using namespace std;

void printArr(int* arr, int count)
{
	for (int i = 0; i < count; i++)
		cout << *(arr + i) << endl;
}

void randArr(int* arr, int count)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> distribution(1, count);

	for (int i = 0; i < count; i++)
		*(arr + i) = distribution(gen);
}

void badInitArr(int* arr, int count)
{
	for (int i = count; i > 0; i--)
		*(arr + i) = i;
}