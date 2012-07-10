#include <stdio.h>

#define N 4
int main()
{
    int arr[N][N];
    int i,j;
    int temp;
    int count = 0;
    for( i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            count++;
            arr[i][j] = count;
        }
    }
    for( i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%5d",arr[i][j]);

        }
        printf("\n");
    }
    for( i = 0; i < N-1; i++)
    {
        for( j = i+1; j < N; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;

        }

    }


    for( i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%5d",arr[i][j]);

        }
        printf("\n");
    }



    return 0;
}
