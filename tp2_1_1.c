#include <stdio.h>
#include <stdlib.h>
#define N 20

void main()
{

    int i;
    double vt[N];
    for (i = 0; i < N; i++)
    {
        vt[i] = 1 + rand() % 100;
        printf("%f \n", vt[i]);
    }
}