#ifndef __RANDOM_H__
#define __RANDOM_H__

#define random(x) (rand()%x)

void setSeed(int num);
const char* genRandNum(const char *fileName, int scope, int size);
int *getRandNumBuf(const char *fileName, int size_num);
#endif
