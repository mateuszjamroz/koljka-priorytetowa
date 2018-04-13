// Prior_queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prior_queue.h"

void PQPrint(PQueue* PQ);
void PQBuild(PQueue* PQ);
#define nSize 20;
#define PRINT

int main()
{
	int Size = nSize;
	PQueue* pqTest = PQInit(Size);
	PQBuild(pqTest);
#ifdef PRINT
	PQPrint(pqTest);
#endif
	PQDeQueue(pqTest);
	PQDeQueue(pqTest);
#ifdef PRINT
	PQPrint(pqTest);
#endif
	PQEnQueue(pqTest, 30, 99);
#ifdef PRINT
	PQPrint(pqTest);
#endif
	PQDeQueue(pqTest);
#ifdef PRINT
	PQPrint(pqTest);
#endif
	PQEnQueue(pqTest, 10, 20);
	PQEnQueue(pqTest, 20, 10);
#ifdef PRINT
	PQPrint(pqTest);
#endif
	IncreaseKey(pqTest, 10, 99);
	DecreaseKey(pqTest, 20, 1);
#ifdef PRINT
	PQPrint(pqTest);
#endif
	PQDeQueue(pqTest);
#ifdef PRINT
	PQPrint(pqTest);
#endif

	PQRealease(&pqTest);

    return 0;
}

void PQPrint(PQueue* PQ)
{
	if (PQEmpty(PQ))
	{
		printf("Queue is empty!\n");
		return;
	}
	for (int i = 0; i < PQ->PQCurrSize; i++)
	{
		printf(" %4d %4d ", PQ->PQueue[i].nKey, PQ->PQueue[i].nPrior);
		printf("\n");
	}
	printf("\n");
}

void PQBuild(PQueue* PQ)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < PQ->PQSize; i++)
	{
		PQEnQueue(PQ, i, rand() % 100);
	}
}
