// πÈ≤¢≈≈–Ú.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void sort(int *array, int p, int q);
void mergeAll(int *array, int p, int q, int r);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {3, 4, 7, 8, 1, 9, 2, 5, 6};

	sort(a, 0, sizeof(a)/sizeof(int)-1);

	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		printf("%d: %d\n", i, a[i]);
	}

	system("PAUSE");
	return 0;
}

void sort(int *array, int p, int q)
{
	if (p >= q)
		return;

	int p1 = p;
	int r1 = q;
	int q1 = p + ((q-p)>>1);

	sort(array, p1, q1);
	sort(array, q1+1, r1);
	mergeAll(array, p1, q1, r1);
}

void mergeAll(int *array, int p, int q, int r)
{
	int *tmpArray = new int[r - p + 1];
	memset(tmpArray, 0, (r - p + 1)*sizeof(int));
	int i = p;
	int j = q+1;
	int k = 0;
	while(i <= q && j <= r)
	{
		if (array[i] < array[j])
		{
			tmpArray[k] = array[i];
			++i;
		}
		else
		{
			tmpArray[k] = array[j];
			++j;
		}
		++k;
	}

	if (i <= q)
	{
		while (i <= q)
		{
			tmpArray[k] = array[i];
			++k;
			++i;
		}
	}
	else if (j <= r)
	{
		while (j <= r)
		{
			tmpArray[k] = array[j];
			++j;
			++k;
		}
	}
	memcpy(array+p, tmpArray, sizeof(int)*(r - p + 1));
	delete []tmpArray;
}