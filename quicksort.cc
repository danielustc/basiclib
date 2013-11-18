#include "common.h"
#include "util.h"

void quickSort(int* a, int l, int r)
{
	if(l>=r)
		return ;
	int i = l + 1;
	int j = r;
	int key = a[l];

	while(1)
	{
		while(a[j]>key)
		{
			j--;	
		}
		while(a[i]<key && i<=j)
		{
			i++;	
		}
		if(i>=j)
		{
			break;	
		}
		swap(&a[i],&a[j]);
		if(a[j]==key)
		{
			j--;	
		}
		else
		{
			i++;	
		}

	}
	swap(&a[l],&a[j]);
			 
	if(l < i - 1)   quickSort(a, l, i - 1);
	if(j + 1 < r)  quickSort(a, j + 1 , r);

}
