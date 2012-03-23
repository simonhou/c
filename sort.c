#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <assert.h>

#define N 10000000
#define N_M 1000000

unsigned char a[8] = {1,2,4,8,16,32,64,128};

int main(int argc, char *argv[])
{
	void randdata(unsigned char *const c);
	int sort();
	unsigned char * const c = (unsigned char * const)malloc(N/8);
	randdata(c);
	sort();
	free(c);
	return 0;
}
//产生100万个0~1000万间无重复的随机数
void randdata(unsigned char *const c)
{
		int i, j, k, idx;
	FILE *fp;
	fp = fopen("data.txt", "w");
	assert(fp != NULL)
	srand(time(NULL));
	for(idx = 0; idx < N_M; )
	{
		//随机数有位数限制
		i = ((rand() << 16)+rand()) % N;
		j = i / 8;
		k = i % 8;
		if((c[j] & a[k]) == 0)
		{
			idx++;
			c[j] |= a[k];
			fprintf(fp, "%d\n", i);
		}
	}
	fclose(fp);
}

//高效排序
int sort()
{
	unsigned char c[N/8] = {0};
	int i, j, k;
	fp = fopen("data.txt", "r");
	assert(fp != NULL)
	while(fscanf(fp, "%d", &i) > 0)
	{
		j = i / 8;
		k = i % 8;
		c[j] |= a[k];
	};
	fclose(fp);
	fp = fopen("sort.txt", "w");
	for( i = 0, j = 0; i < N/8; i++)
	{
		if(c[j] == 0) continue;
		else
		{
			for(j = 0; j < 8; j++)
			{
				if(c[i] & a[j])
					fprintf(fp, "%d\n", (i<<3)+j);
			}
		}
	}
	fclose(fp);
	return 0;
}
