// test-four.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <ctype.h>
#include <string>
#define MAX 5000+10
char buf[MAX],s[MAX];
/*
int _tmain(int argc, _TCHAR* argv[])
{
	int m,n;
	m = 0;
	n = 0;
	int max = 0;
	fgets(buf,sizeof(s),stdin);
	n = strlen(buf);
	for(int i = 0;i<n;i++)
		if(isalpha(buf[i]))
			s[m++] = toupper(buf[i]);
	for(int i = 0;i<m;i++)
	{
		for(int j = i;j<m;j++)
		{
			int ok = 1;
			for(int k = i;k<=j;k++)
			{
				if(s[k]!=s[i+j-k])
					ok = 0;
			}
			if(ok&&j-i+1>max)
				max = j-i+1;
		}
	}
	printf("max len is %d",max);
	return 0;
}

*/
int p[MAX];
int main()
{
	int m,n,x,y,j,i;
	m = 0;
	n = 0;
	int max = 0;
	fgets(buf,sizeof(s),stdin);
	n = strlen(buf);
	for(int i = 0;i<n;i++)
		if(isalpha(buf[i]))
		{
			p[m] = i;//��m���ַ���Ӧԭ��λ��
			s[m++] = toupper(buf[i]);
		}
	for(i = 0;i<m;i++)
	{
		for(j = 0;i-j>=0&&i+j<m;j++)//��i��������  �ܳ�����
		{
			if(s[i-j]!=s[i+j]) break;
			if(2*j+1>max)
			{
				max = 2*j+1;
				x = p[i-j];
				y = p[i+j];
			}
		}
		for(j = 0;i-j>=0&&i+j+1<m;j++)//��i i+1�������� �ܳ�ż��
		{
			if(s[i-j]!=s[i+j+1]) break;
			if(2*j+2>max)
			{
				max = 2*j+2;
				x = p[i-j];
				y = p[i+1+j];
			}
		}
	}
	for(i = x;i<=y;i++)
	{
		printf("%c",buf[i]);
	}
	printf("\n");
	return 0;
}