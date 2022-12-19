#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int  StrEqual(char* p, char str[])
{
	char* ptr = str;
	while (*ptr != '\0')
	{
		if (*p != *ptr)
		{
			break;
		}
		p++;
		ptr++;
	}
	if (*ptr == '\0')return 1;
	else return 0;
}
void jiaohuan(char* p, char str2[], char str3[])
{
	if (strlen(str2) <= strlen(str3))//需要从p+strlen(str2)开始移动，移动strlen(str3)-strlen(str2)个长度
	{
		//空出位置
		for (int j = 0; j < strlen(str3) - strlen(str2); j++)//空出strlen(str3)-strlen(str2)个空格
		{
			int n = 0;
			for (n = 0; *(p + n) != '\0'; n++);//找到末尾
			for (int i = 0; p + n - i >= p + strlen(str2); i++)
			{
				*(p + n + 1 - i) = *(p + n - i);
			}
		}

		//替换中
		for (int i = 0; str3[i] != '\0'; i++)
		{
			*(p + i) = str3[i];
		}

	}
	else
	{
		for (int j = 0; *(p + strlen(str3) + j) = *(p + strlen(str3) + j + 1); j++);//先填掉没用的空格
		//开始替换
		for (int i = 0; str3[i] != '\0'; i++)
		{
			*(p + i) = str3[i];
		}
	}

}
void tihuan(char str1[], char str2[], char str3[])
{
	char* p1 = str1;
	char* p2 = str2;
	char* p3 = str3;
	while (*p1 != '\0')
	{
		while (*p1 != *p2 && *p1 != '\0')
		{
			p1++;
		}
		if (StrEqual(p1, str2) == 1)
		{
			jiaohuan(p1, str2, str3);
		}
		p1++;
	}

}
int main(void)
{
	char str1[100];
	printf("请输入源字符串:\n");
	gets(str1);
	char str2[50];
	printf("请输入想替换的字符串:\n");
	gets(str2);
	char str3[80];
	printf("请输入想替换成的字符串:\n");
	gets(str3);
	//处理区

	tihuan(str1, str2, str3);

	//输出区
	printf("替换后的字符串为:\n");
	printf("%s", str1);
	system("pause");
	return 0;
}
