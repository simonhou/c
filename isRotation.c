#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            return i- strlen(str2);  /* ����str1����ͬstr2�ַ�������ʼλ��*/
        }

        i = i - j + 1;  /* ���������������� */
    }
    return -1;     /* Dismatch */
}

int KMP(char* str1, char* str2)
{
    int* next;   /* ���ڱ����ж�ǰ׺��׺���� */
    next = (int*)malloc(sizeof(int)*strlen(str2));

    if(!next)
        return -1;  /* Allocation Failure */
    int i,j;
    i = 0;
    j = 0;
    getnext(str2,next);
    while( i < strlen(str1) && j < strlen(str2))
    {
        if( j == -1 || str1[i] == str2[j] )
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];  /* ��BF���Ĳ�ͬ��i����Ҫ���� */
        }

    }
    free(next);   /*Don't forget to release heap */

    if( j = strlen(str2))
        return i - strlen(str2);

    return -1;   /* Dismatch */

}

void getnext(char* str,int *next)
{
    int k,j;
    next[0] = -1;
    j = 0;
    k = -1;  /* kΪ����jλ����ʧ��ʱ����Ҫ�ƶ�������һ�ν��бȽϵ�λ */
    while( j < strlen(str) )
    {
        if( k == -1 || str[j] == str[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
         k = next[k];  /* Matching Failure */
    }
}

int isRotation(char* str1, char *str2)
{
    if(strlen(str1) == strlen(str2))
    {
        char* cpy = (char*)malloc(sizeof(char)*strlen(str1)*2);
        strcpy(cpy,str1);  /* �����¿ռ����Դ���ַ��� */

        strcat(cpy,str1);  /* ���ַ������Լ�ƴ�� */

        return isSubstr(cpy,str2);
    }
    else return -1;

}

int main()
{
    char* str1 = "bottlewater";
    char* str2 = "eebottlewat";

    printf("Rotation��%d\n",isRotation(str1,str2));

    printf("KMP:%d\n",KMP(str1,str2));

    printf("BF:%d\n",isSubstr(str1,str2));

    return 0;
}
