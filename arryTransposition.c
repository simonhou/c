#include <stdio.h>

void InputMatrix(int (*a)[4], int , int);
void OutputMatrix(int (*b)[3], int, int);
void MatrixTranspos(int (*a)[4],int (*b)[3]);

int main()
{
	int a[3][4], b[4][3];
    InputMatrix(a, 3, 4);
	MatrixTranspos(a, b);
	printf("The Transposed Matrix is\n");
	OutputMatrix(b, 4, 3);
	getchar();
	return 0;
}

void InputMatrix(int (*a)[4], int n , int m)
{
	int i,j;
	printf("Please input matrix:\n");
	for(i = 0; i < n; i++)
		for (j = 0; j< m; j++)
			scanf("%d", *(a+i)+j);
}

void OutputMatrix(int (*b)[3], int n, int m)
{
	int i, j;
	for(i = 0; i < n ; i++)
	{
		for(j = 0; j < m; j++)
			printf("%d\t", *(*(b+i)+j));
		printf("\n");
	}
}

void MatrixTranspos(int (*a)[4], int (*b)[3])
{
	int i,j;
	for(i = 0;i < 4; i++)
		for(j = 0; j < 3; j++)
			b[i][j] = a[j][i];
}
