#include <stdio.h>
#define M 5
void trs(int (*)[M]);
void trs2(int (*)[M]);
void trs3(int (*arr)[M]);

int main(void)
{
	int i,j;
	int a[M][M] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{1,2,3,4,5},{1,2,3,4,5}};
//	trs2(a);
	trs3(a);
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < M; j++)
		{
			printf("%d\t",*(*(a+i)+j));
		}
		printf("\n");
	}
	return 0;
}

void trs(int (*arr)[M])
{
	int i, j, t=0;
	for(i = 0;i < M; i++)
		for(j = 0; j < i; j++)
		{
            t = arr[i][j]; 
			arr[i][j] = arr[j][i];
			arr[j][i] = t;
		}

}
void trs2(int (*arr)[M])
{
	int i, j;
	for(i = 0; i < M; i++)
	{
		int *p = &arr[i][i];
		for(j = i+1; j < M; j++)
		{
		
			int t = arr[i][j];
			arr[i][j] = *(p + M);
			*(p + M) = t;
			p += M;
		}
	}
}

void trs3(int (*arr)[M])
{
	int i,j;
	int *q = arr[1];
	for(i = 1; i < M; i++)
	{
		int *p = &arr[0][i];
		{
			for(j = 0; j < i; j++)
			{
//				int t1 = *p;
				int t2 = q[j];
				q[j] = *p;
				*p = t2;
				p += M;
			}
			q += M;
		}
	}
}
