#include "common.h"
#include "random.h"

void setSeed(int num)
{
	srand(num);	
}

const char* genRandNum(const char *fileName, int scope, int size) 
{
	FILE *fp = NULL;
	fp = fopen (fileName, "w");
	char buf[2048];
	memset(buf,0,sizeof(buf));
	if(NULL == fp)
	{
		printf("open %s fail, pleas check the disk space\n", fileName);	
		return NULL;
	}
	setSeed((int)time(0));
	for(int i=0; i<size; i++)
	{
		int tmp = random(scope);	
		sprintf(buf, "%3d", tmp);
		fwrite(buf,strlen(buf),1,fp);
		if(0 == (i+1)%15) 
		{
			fwrite("\n",1,1,fp);
		}
		else
		{
			fwrite(" ",1,1,fp);	
		}
	}
	fclose(fp);
	return fileName;
}

int *getRandNumBuf(const char *fileName, int size_num)
{
	FILE *fp = fopen(fileName, "r");
	if(NULL == fp)
	{
		printf("No file %s\n", fileName);	
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
    char *buf = (char *)malloc(size);
	memset(buf,0,sizeof(buf));
	fseek(fp, 0, SEEK_SET);
	for(int i=0; i<size; i++)
	{
		fread(buf+i, 1, 1, fp);
	}

	int* numBuf = (int *)malloc(size_num*sizeof(int)); 
	int numCounter = 0;
	char tmpBuf[10];
	memset(tmpBuf,0,sizeof(tmpBuf));
	int j = 0;
	for(int i=0; i <size; i++)
	{
		if( *(buf+i)!=' ' && *(buf+i)!='\n')
		{
			tmpBuf[j] = buf[i];			
			j++;
		}
		else
		{
			if(0!=j)	
			{
				numBuf[numCounter] = atoi(tmpBuf);
				numCounter++;
				memset(tmpBuf,0,sizeof(tmpBuf));
				j=0;
			}
		}
	}
	free(buf);
	return numBuf;
}
