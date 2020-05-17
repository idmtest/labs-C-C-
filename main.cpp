#include "utils.h"
#include "arraysort.h"

using namespace std;

int main(int argc, char* argv[])
{
	while (1)
	{
		int count = 0;
		int workTime = 0;
		short curAlg = 0;
		bool needPrint = 0;
		ErrorProg error = NoError;
		SortFunc pSortFunc = NULL; // ptr to func

		curAlg = showMenu();

		switch (curAlg)
		{
		case 1: pSortFunc = foolSort; break;
		case 2: pSortFunc = bubleSort; break;
		case 3: pSortFunc = wrongBubleSort; break;
		case 4: pSortFunc = bogoSort; break;
		case 5: myEndProg(); break;
		default:
			restartMenu(InputError);
			continue;
		}

		cout << "Input count array: ";
		cin >> count;
		if (!checkInput(&count, 2))
			restartMenu(InputError);

		needPrint = count < 10 ? true : false; // if need print array

		int* arrNotSort = NULL;
		int* arrForSort = NULL;
		
		arrNotSort = (int*)malloc(count * sizeof(int));
		arrForSort = (int*)malloc(count * sizeof(int));

		if (arrNotSort == NULL
			|| arrForSort == NULL) // ToDo add free() if one of array first allocated
		{
			restartMenu(MemmoryError);
			continue;
		}

		randArr(arrNotSort, count);
		memcpy(arrForSort, arrNotSort, count * sizeof(int));

		if (needPrint)
			printArr(arrNotSort, count);

		workTime = pSortFunc(arrForSort, count); // work time

		if (needPrint)
			printArr(arrForSort, count);

		cout << "\nWorkTime is " << workTime;

		free(arrNotSort); 
		free(arrForSort);

		restartMenu(NoError);
	}
}