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
            return i- strlen(str2);  /* ����str1����ͬstr2�ַ�������ʼλ��*/
        }
        i = i - j + 1;  /* ���������������� */
    }

}

int KMP(char* str1, char* str2)
{
    int next[100];   /* ���ڱ����ж�ǰ׺��׺���� */
    int i,j;
    i = 0;
    j = 0;
    getnext(str2,next);
    while( i < strlen(str1))
    {
        if( j = -1 || *(str1+i) == *(str2+j) )
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];  /* ��BF���Ĳ�ͬ��i����Ҫ������ */
        }
        if( j = strlen(str2))
            return i - strlen(str2);
    }

    return -1;


}

void getnext(char* str,int *next)
{
    int k,j;
    next[0] = -1;
    j = 0;
    k = -1;
    while( j < strlen(str) - 1)
    {
        if( k = -1 || str[j] == str[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
         k = next[j];  /* Matching Failure */
    }


}

int main()
{
    char* str1 = "ababdeababc";
    char* str2 = "ababc";
    printf("%d\n",isSubstr(str1,str2));

    return 0;
}
