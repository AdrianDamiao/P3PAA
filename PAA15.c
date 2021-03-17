#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int _max(int a, int b)
{
    return a >= b ? a : b;
}

int max_recursiv_1(int *v, int tam)
{
    if (tam == 1)
    {
        return v[0];
    }
    else
    {
        return _max(max_recursiv_1(v, tam - 1), v[tam - 1]);
    }
}

int main()
{

    srand(time(NULL));

    struct timeval start, stop;
    int n = 0;
    int i, j;
    int sum = 0;

    printf("Tamanho do Vetor:");
    scanf("%d", &n);

    int *vetor;
    vetor = malloc(n * sizeof(int));

    for (i = n; i >= 0; i--)
    {
        vetor[i] = i;
    }

    for (i = 0; i < n; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    gettimeofday(&start, NULL);
    printf("\nMaximo = %d", max_recursiv_1(vetor, n));
    gettimeofday(&stop, NULL);
    long seconds = stop.tv_sec - start.tv_sec;
    long microseconds = stop.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    printf("\nElapsed: %lf", elapsed);

    gettimeofday(&start, NULL);
    for (i = 0; i < n; i++)
    {
        for (j = 1, sum = vetor[0]; j <= i; j++)
        {
            sum += vetor[j];
        }
        //printf("\nA soma do sub-vetores de 0 ate %d e %d", i, sum);
    }
    //MergeSort(vetor, n);
    printf("\nMaximo2 = %d", vetor[n - 1]);
    gettimeofday(&stop, NULL);
    seconds = 0;
    seconds = stop.tv_sec - start.tv_sec;
    microseconds = 0;
    microseconds = stop.tv_usec - start.tv_usec;
    elapsed = 0;
    elapsed = seconds + microseconds * 1e-6;
    printf("\nElapsed2: %lf", elapsed);

    free(vetor);
}