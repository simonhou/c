#include <stdio.h>
int find_xor(int *a, int N)
{
	int i = 0;
	int result = 0;
	for(i = 0; i < N; i++)
		result ^= a[i];
	for(i = 1; i < N; i++)
		result ^= i;
	return (result);
}

int find_sum(int *a, int N)
{
	int i = 0;
	int result = 0;
	int sum = 0;
	for(i = 0; i < N; i++)
	{
		result += a[i];
		sum += i;
	}
	return (result-sum);
}

int main()
{
	int a[]={1,2,3,3,4};
	int res;
	res = find_xor(a,5);

	printf("XOR method: %d\n", res);
	printf("sum method:%d\n", find_sum(a,5));
	return 0;
}

