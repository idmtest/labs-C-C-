#include "utils.h"
using namespace std;

void printArr(int* arr, int count)
{
	for (int i = 0; i < count; i++)
		cout << *(arr + i) << endl;
	printf("-------------\n");
}

void randArr(int* arr, int count) // init arr random varibles from 1 to count
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> distribution(1, count);

	for (int i = 0; i < count; i++)
		*(arr + i) = distribution(gen);
}

void badInitArr(int* arr, int count) // ToDo
{
	for (int i = count; i > 0; i--)
		*(arr + i) = i;
}

bool checkInput(void* inpvar, short flag) // if diff type to check
{
	if (flag == 1) // for choose type short
	{
		if (*((short*)inpvar) <= 0)
			return false;
	}

	if (flag == 2) // for choose type int
	{
		if (*((int*)inpvar) <= 0)
			return false;
	}

	return true;
}

void restartMenu(ErrorProg err)
{
	switch (err)
	{
	case MemmoryError:
		cout << "Memory not allocated, please try again\n";
	case InputError:
		cout << "Input error, please try again\n";
	}
	cout << "\nPress any key to menu\n";
	_getch();
}

short showMenu()
{
	short alg = 0;
	system("cls");
	cout << "Available Methods \n"
		"1- Fool sort\n"
		"2- Bubble sort\n"
		"3- Worng bubble sort\n"
		"4- Monkey sort\n"
		"5 - Exit\n"
		"Choose methog : ";
	cin >> alg;
	
	return alg;
}

void myEndProg()
{
	cout << "\nEnd prog. Input any key";
	_getch();
	exit(0);
}