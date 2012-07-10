#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int findAnagrams(char * str1, char *str2);
int main()
{
    char str1[] = "helloworld";
    printf("%d\n",*(str1+4));
 //   char str2[] = "helwalordl";
    char str2[] = "helwolordl";
    int result = findAnagrams(str1, str2);
    printf("%d\n", result);
    return 0;

}


int findAnagrams(char * str1, char *str2)
{
    int arr[256];
    int i;
    int uniqueSum = 0;
    int completSum = 0;
    for(i = 0; i < 256; i++)
    {
        arr[i] = 0;
    }

    if(strlen(str1) != strlen(str2))  /* 长度不等肯定不是同构的 */
        return 1;

    for( i = 0; i < strlen(str1); i++)
    {
        if(arr[*(str1+i)] == 0)
        {
            ++uniqueSum;    /* 统计不同字符总数 */
        }
        ++arr[*(str1+i)];   /* 统计相同字符出现的次数 */
    }

    for( i = 0; i < strlen(str2); i++)
    {
        if(arr[*(str2+i) == 0])
        {
            return 1;       /* str2中有字符没有在arr数组中出现，说明不是同构 */
        }
        else
        {
            arr[*(str2+i)]--;
        }
        if(arr[*(str2+i)] == 0)
        {
            ++completSum;
            if(completSum == uniqueSum)
            {
                return 0;
            }

        }
    }
    return 1;

}
