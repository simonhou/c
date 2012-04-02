#include <stdio.h>
#include <stdlib.h>

typedef struct Jew
{
	int number;
	struct Jew *next; //指向下一个
}Jew;

int main()
{
	Jew *jew;
	Jew *r;
	int N;
	int M;
	int i;
	printf("Please input number of Jew(N) and interval(M):\n");
	scanf("%d, %d", &N, &M);
	jew = (Jew *)malloc(N * sizeof(Jew));
	r = jew;
	for(i = 1; i < N; i++)
	{
		r->number = i;
		r->next = jew + i;
		r = r->next;
	}
	r->number = N;
	r->next = jew; //循环链表
	printf("Suicide order:\n");
	while( r != r->next)
	{
		for(i = 0; i < (M-1); i++)
			r = r->next;
		printf("%4d", r->next->number);
		r->next = r->next->next;
	}
	printf("\n When N = %d and M = %d, Josephua, hiding in position %d survies.\n", N, M, r->number);
	free(jew);
	return 0;
}
