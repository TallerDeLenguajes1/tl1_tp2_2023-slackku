#include <stdio.h>
#include <stdlib.h>
#define N 20

void main()
{

    int i;
    double vt[N], *pVt;
    pVt = vt;
    for (i = 0; i < N; i++)
    {
        pVt[i] = 1 + rand() % 100;
        printf("%f \n", pVt[i]);
        pVt++;
    }
}