#include <stdio.h>
#include <stdlib.h>

#define M 7
#define N 5

int main()
{
    int i, j;
    int **mt = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++)
    {
        mt[i] = (int *)malloc(M * sizeof(int));
        for (j = 0; j < M; j++)
        {
            mt[i][j] = 1 + rand() % 100;
            printf("%d|", mt[i][j]);
        }
        printf("\n");
    }

    return 0;
}