#include <stdio.h>
#include <string.h>
#include <assert.h>

char *mystrcpy(char *dst, char* src)
{
	char *d = dst;
	char *s = src;
	int count = 0;
	assert(dst);
	assert(src);

	if( dst == src)
	{
		return src;
	}
	count = strlen(src) + 1;   //计算src字符长度
	if(count <= 1)		//说明src字符串内容为空
		return 0;
	if(dst < src || dst >= (src + count))
	{	
		while(count--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = dst + count;
		s = src + count;
		while(count--)
			*d-- = *s--;
	}

	return dst;
}

int main()
{
	char *src = "Hello world!";
	char dst[20] = {0};
	mystrcpy(dst, src);
	printf("dst is %s\n", dst);
	return 0;
		
}
