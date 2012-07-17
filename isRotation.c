#include <stdio.h>
#include <string.h>
int isSubstr(char* str1, char *str2)
{
    int i = 0;
    int j;
    while( i < strlen(str1))
    {
        j = 0;
        while( *(str1+i) == *(str2+j) && j < strlen(str2))
        {
            i++;
            j++;
        }
        if( j == strlen(str2))
        {
            return i- strlen(str2);  /* 返回str1中相同str2字符串的起始位置*/
        }
        i = i - j + 1;  /* 如果不是则继续回溯 */
    }

}

int main()
{
    char* str1 = "ababdeababc";
    char* str2 = "ababc";
    printf("%d\n",isSubstr(str1,str2));

    return 0;
}
