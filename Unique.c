#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isUniqueCh1(char*);
int isUniqueCh2(char*);
int main()
{
    int i;
    char* str[5] = {"abcde", "hello", "apple", "kite", "padle"}; /* 定义一个char指针数组，既每个元素都是指针 */
    for(i = 0; i < 5; i++)
    {
        printf("%s:",str[i]);
        if(isUniqueCh1(str[i]) == 0)
        {
            printf("Not Unique!\n");
        }
        else
        {
            printf("Unique!\n");
        }
    }

    return 0;

}

int isUniqueCh1(char * str)
{
    int i,j;

    int n = strlen(str);   /* 输入字符串的长度 */
    int value;

    for(i = 0; i< n-1; i++)
    {
        for(j = n-1; j > i; j--)
        {
            value = *(str+i) - *(str+j);  /* 两个字符ASCII码是否相减为0判断相等 */
            if( value == 0 )
            {
                return 0;    /* 不唯一 */
            }

        }
    }
    return 1;  /* 唯一 */

}

int isUniqueCh2(char* str)
{
    int n = strlen(str);
    int i;
    int value;         /* 保存相应字符的ASCII码值 */
    int checker = 0;
    for( i = 0; i < n; i++)
    {
        value = *(str+i) - 'a';

        if((checker & (1 << value)) > 0)
        {
            return 0;  /* Not Unique */
        }
        checker |= 1 << value;
    }

    return 1;

}
