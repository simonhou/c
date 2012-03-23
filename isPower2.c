#include <stdio.h>
int isPower2(int x)
{
	int i = !!(x ^ 0);
	return (!((x&(~x+1)) + (~x + 1))) & i; 
}

int main()
{
	int x;
	printf("Please input a number:\n");
	scanf("%d", &x);
	if(isPower2(x))
		printf("It is power of 2!\n");
	else
		printf("It is not power of 2!\n");
	return 0;
}
