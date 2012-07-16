#include <stdio.h>

#define M 3
#define N 3

int main()
{
    int arr[M][N] = {{1,2,1},
                     {3,0,1},
                     {0,4,2}};
    int row[M];
    int column[N];
    int i,j;

    for(i = 0; i < M; i++)
    {
        for( j = 0; j < N; j++)
        {
            if(arr[i][j] == 0)
            {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(row[i] == 1 || column[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }

    for(i = 0; i < M; i++)
    {
        for( j = 0; j < N; j++)
        {
            printf("%5d",arr[i][j]);

        }
        printf("\n");
    }

}
