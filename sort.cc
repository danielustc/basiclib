#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"
#include "common.h"
#include "util.h"
#include "linklist.h"

void displayBuf(int *buf, int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%3d ", buf[i]);
		if((i+1)%15==0)
			printf("\n");
	}
	printf("===========================================================\n");
}

int main()
{
	const char* srcFile = "unsorted.txt";
	const int scope = 1000;
	const int size  = 20;
//	const char *ret = genRandNum(srcFile, scope, size); 
//	if(!ret) {exit(0);}

	int *srcBuf = getRandNumBuf(srcFile, size);
	linklist head ;
	for(int i=0;i<size;i++)
	{
		head.addNode(srcBuf[i]);	
		head.addNode(new node(srcBuf[i]));	
	}
	head.printAll();
	printf("size=%d\n",head.size());
	head.reverse();
	head.printAll();
	printf("size=%d\n",head.size());
	//displayBuf(srcBuf, size);
	//quickSort(srcBuf, 0, size-1);
	//displayBuf(srcBuf, size);
	//reverse(srcBuf, size);
	//displayBuf(srcBuf, size);
	free(srcBuf);
	return 1;
}
