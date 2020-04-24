#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <chrono>
#include "utils.h"

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

	chrono::time_point<chrono::system_clock> start, end;
	
	int* arrForSort = new int [count];
	
	randArr(arrForSort, count);
	start = chrono::system_clock::now();

	printArr(arrForSort, count);

	end = chrono::system_clock::now();

	int workTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "WorkTime is " << workTime;

	
	delete []arrForSort;

	myEndProg();

}