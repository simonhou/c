#include <stdio.h>
#include <math.h>
int sum(int );
void Prime(int );
int main(void)
{
	int N;
	printf("Please input a number:\n");
	scanf("%d", &N);
	Prime(N);
	printf("The sum of Prime number is:%d\n",sum(N));
	return 0;
}

int sum(int N)
{
	int nCount = 0;
	int nSum = 0;
	int n = 2;
	int i = 0;
	while(1)
	{
		/*偶数不是质数，剔除*/
		if( n > 2 && n%2 == 0)
		{
			n++;
			continue;
		}
		/*计算是否质数*/
		for(i = 2; i < n; i++)
		{
			if( 0==n%i)
				break;
		}
		/*i,n相等则是质数*/
		if( i == n)
		{
			printf("Prime %d\n", n);
			nCount++;
			nSum += n;
			if(nCount == N)
			{
				return nSum;
			}
		}
		n++;
	}
	return 0;
}

void Prime(int M)
{
	int i ;
	int k = sqrt(M);
	for( i = 2; i <= k; i++)
		if(0 == M%i)
			break;
	if(i > k)
		printf("%d is a prime number\n",M);
	else
		printf("%d is not a prime number\n",M);
}
