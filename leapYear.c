#include <stdio.h>

int main()
{
	int year;
	printf("Please input a number:\n", year);
	scanf("%d", &year);
	if((year%4 == 0 & year % 100 != 0)||(year % 400 == 0))
		printf("%d is leap year!\n", year);
	else
		printf("%d is not leap year!\n", year);
	getchar();
	return 0;
}

