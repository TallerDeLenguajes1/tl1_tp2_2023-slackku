#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7
void main()
{
    int i, j;
    int mt[N][M], *pMt;

    pMt = &mt[0][0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *pMt + i + j; 
            *pMt = 1 + rand() % 100;
            printf(" %d ", (*pMt + i + j));
        }
        printf("\n");
    }
}