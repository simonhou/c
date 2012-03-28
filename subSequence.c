#include <stdio.h>
int max_sub(int a[], int size);

int main()
{
	int a[]={-2,11,-4,13,-5,2,-5,-3,12,-9};
	int sum;
	sum = max_sub(a, 10);
	printf("sum is %d\n", sum);
	return 0;

}

int max_sub(int a[], int size)
{
	int i, max = 0, temp_sum = 0;
	for(i = 0; i < size; i++)
	{
		temp_sum += a[i];
		if (temp_sum > max)
			max = temp_sum;
		else if(temp_sum < 0)
			temp_sum = 0;
	}
	return max;
}
