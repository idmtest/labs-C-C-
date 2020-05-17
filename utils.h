#pragma once
#include <iostream>
#include <random>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <array>
#include <chrono>

typedef enum _errorProg
{
	NoError = 0,
	MemmoryError,
	InputError
} ErrorProg;


void printArr(int* arr, int count);
void randArr(int* arr, int count);
bool checkInput(void* inpvar, short flag);
void restartMenu(ErrorProg err);
void myEndProg();
short showMenu();

//for chrono
typedef std::chrono::time_point<std::chrono::system_clock> myTypeTime;