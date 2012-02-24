#include <stdio.h>

void deTobi(int a);

int main()
{
	int i;
	printf("Please in put a mumber:\n");
	scanf("%d", &i);
	deTobi(i);
	getchar();
	return 0;
}

void deTobi(int a)
{
	int i = 0, stack[10], r, s;
	do{
		r = a / 2;
		s = a % 2;
		stack[i] = s;
		if(r != 0)
		{
			i++;
		    a = r;
		}
	}while(r);
	for(; i>= 0; i--)
		printf("%d", stack[i]);
	printf("\n");
}
