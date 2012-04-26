#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef struct SqList{
	int r[MAXSIZE+1];
	int length;
}SqList;

int partion(SqList *, int , int );
void QSort(SqList *, int , int );

void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void BubbleSort0(SqList *L)
{
	int i, j;
	for(i = 0; i < L->length-1; i++)
	{
		for(j = i+1; j < L->length; j++)
		{
			if(L->r[i] > L->r[j])
			{
				swap(L, i, j);
			}
		}
	}
}

void BubbleSort(SqList *L)
{
	int i, j;
	for( i = 1; i < L->length; i++)
	{
		for(j = L->length-1; j >= i; j-- )
		{
			if(L->r[j] > L->r[j+1])
			{
				swap(L, j, j+1);
			}
		}
	}
}

void BubbleSort2(SqList *L)
{
	int i,j;
	int flag = 1;
	for( i = 1; i < L->length && flag; i++)
	{
		flag = 0;
		for( j = L->length-1; j >= i; j--)
		{
			if(L->r[j] > L->r[j+1])
			{
				swap(L, j, j+1);
				flag = 1;
			}
		}

	}
}

void SelcSort(SqList *L)
{
	int i,j,min;
	for( i = 1; i < L->length; i++)
	{
		min = i; // 假设当前下标为i的数最小
		for( j = i+1; j <= L->length; j++)
		{
			if(L->r[min] > L->r[j])
				min = j;      // 找出最小值的关键字，给min
		}
		if(i != min)
			swap(L, i, min);
	}
}
// 将i记录保存在哨兵0位置，依次比较1～i-1元素与0位置元素大小
void InsertSort(SqList *L)
{
	int i,j;
	for(i = 2; i < L->length; i++)
	{
		if(L->r[i] < L->r[i-1])
		{
			L->r[0] = L->r[i];
			for( j = i-1; L->r[j] > L->r[0]; j--)
				L->r[j+1] = L->r[j]; // 记录后移
			L->r[j+1] = L->r[0];
		}
	}
}
// shell 排序是直接插入排序的改进版
void shellSort(SqList *L)
{
	int i, j;
	int increment;
	increment = L->length;
	do
	{
		increment = increment / 3 + 1;
		for(i = increment + 1; i <= L->length; i++)
		{
			if( L->r[i] < L->r[i - increment])
			{
				L->r[0] = L->r[i];
				for(j = i - increment; j > 0 && L->r[0] > L->r[j]; i -= increment)
					L->r[j+increment] = L->r[j];
				L->r[j+increment] = L->r[0];
			}
		}

	}while(increment > 1);
	
}
/*快速排序算法使用了动态规划的思想，首先将一列元素以pivot为轴心点，左边为小值元素，右边为大值元素
 *然后再对每边的元素递归划分.
 * 快速排序应该是性能最好的排序算法，对其能够进行的优化主要集中在pivot的选择上面，包括随机算则和中间值选择
 */
void quickSort(SqList *L)
{
	QSort(L, 1, L->length);
}

void QSort(SqList *L, int low, int high)
{
	int pivot;
	if(low < high)
	{
		pivot = partion(L, low, high);/* 将L->r[low...high]一分为二*/
		QSort(L, low, pivot-1);
		QSort(L, pivot+1, high);
	}
}

int partion(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];
	while(low < high) /* 外部循环控制终止, 从表的两端交替向中间扫描*/
	{
		while(low < high && pivotkey <= L->r[high])
			high--;
		swap(L, low, high); /*将比枢轴记录小的记录交换到低端*/
		while(low < high && pivotkey >= L->r[low])
			low++;
		swap(L, low, high); /*将比枢轴记录大的记录交换到高端*/
	}
	return low;
}

int main()
{
	int i;
	SqList *L = (SqList*)malloc(sizeof(SqList));
//	L->r[10] = {1,3,2,5,7,6,9,0,4,8};
	L->length = 10;
	printf("Please input 10 numbers:\n");
	for(i = 1; i <= L->length; i++)
		scanf("%d",&L->r[i]);
	printf("The 10 numbers are:\n");
	for(i = 1; i <= L->length; i++)
		printf("%d\t", L->r[i]);
	//BubbleSort(L);
//	SelcSort(L);
	quickSort(L);
	printf("\nSorted:The 10 numbers are:\n");
	for(i = 1; i <= L->length; i++)
		printf("%d\t", L->r[i]);
	printf("\n");
	free(L);
	return 0;
}

