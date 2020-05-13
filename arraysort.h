#pragma once
int foolSort(int* arr, int count);
int wrongBubleSort(int* arr, int count);
int bubleSort(int* arr, int count);
int monkeySort(int* arr, int count);
int bogoSort(int* arr, int size);

typedef int (*SortFunc)(int* arr, int size); // указатель на функцию