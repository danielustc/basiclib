#include "util.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int * a, int size)
{
	for(int i=0; i<size/2;i++)
	{
		swap(&a[i],&a[size-1-i]);		
	}
}
