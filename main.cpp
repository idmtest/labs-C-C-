#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <chrono>
#include <array>
#include "utils.h"
#include "arraysort.h"
using namespace std;

void myEndProg()
{
	_getch();
	exit(0);
}

int main(int argc, char* argv[])
{
	int count = 0;
	int workTime = 0;
	short curAlg = 0;



	cout << "Available Methods \n"
		"1- Fool sort\n"
		"2- Bubble sort\n"
		"3- Worng bubble sort\n"
		"Choose methog : \n";
	cin >> curAlg;

	cout << "Input count array: ";
	cin >> count;

	int* arrNotSort = new int[count];
	int* arrForSort = new int[count];

	randArr(arrNotSort, count);
	memcpy(arrForSort, arrNotSort, count * sizeof(int));

	switch (curAlg)
	{
	case 1: workTime = foolSort(arrForSort, count); break;
	case 2: workTime = bubleSort(arrForSort, count); break;
	case 3: workTime = wrongBubleSort(arrForSort, count); break;
	}
	
	
	//printArr(arrNotSort, count);
	//printf("-------------\n");
	
	 
	cout << "\nWorkTime is " << workTime;

	
	delete []arrNotSort;
	delete[]arrForSort;

	myEndProg();

}