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
	cout << "Input count array: ";
	cin >> count;

	// for elapsed time
	chrono::time_point<chrono::system_clock> start, end;
		
	int* arrNotSort = new int [count];
	int* arrForSort = new int[count];

	randArr(arrNotSort, count);	
	memcpy(arrForSort, arrNotSort, count * sizeof(int));
	
	//start = chrono::system_clock::now();
	//foolSort(arrForSort, count);
	//end = chrono::system_clock::now();
	
	//printArr(arrNotSort, count);
	//printf("-------------\n");
	
	start = chrono::system_clock::now();
	bubleSort(arrForSort, count);
	end = chrono::system_clock::now();
	
	
	//printArr(arrForSort, count);
	

	int workTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "\nWorkTime is " << workTime;

	
	delete []arrNotSort;
	delete[]arrForSort;

	myEndProg();

}