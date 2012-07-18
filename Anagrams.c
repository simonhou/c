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

    if(strlen(str1) != strlen(str2))  /* ���Ȳ��ȿ϶�����ͬ���� */
        return 1;

    for( i = 0; i < strlen(str1); i++)
    {
        if(arr[*(str1+i)] == 0)
        {
            ++uniqueSum;    /* ͳ�Ʋ�ͬ�ַ����� */
        }
        ++arr[*(str1+i)];   /* ͳ����ͬ�ַ����ֵĴ��� */
    }

    for( i = 0; i < strlen(str2); i++)
    {
        if(arr[*(str2+i) == 0])
        {
            return 1;       /* str2�����ַ�û����arr�����г��֣�˵������ͬ�� */
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
