// insertsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

void insertsort(int *array, int length);

int main(int argc, char* argv[])
{
	int a[] = {8,2,1,5,7,6,4};

	insertsort(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		printf("%d: %d\n", i, a[i]);
	}
	system("PAUSE");
	return 0;
}

void insertsort(int *array, int length)
{
	for (int j = 1; j < length; ++j)
	{
		int key = array[j];
		int i = j - 1;
		while (i >= 0 && array[i] > key) {
			array[i+1]=array[i];
			--i;
		}

		array[i+1] = key;
	}
}

