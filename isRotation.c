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

int main()
{
    char* str1 = "ababdeababc";
    char* str2 = "ababc";
    printf("%d\n",isSubstr(str1,str2));

    return 0;
}
