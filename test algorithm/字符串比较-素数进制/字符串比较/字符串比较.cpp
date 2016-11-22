// 字符串比较.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAXSIZE 10000
int prime[MAXSIZE];
int res[MAXSIZE];
int num=0;
int p[28];
int su[20];
int use[20];
void init()
{
	memset(prime,1,sizeof(prime));
	memset(p,0,sizeof(p));
	memset(su,0,sizeof(su));
	memset(use,0,sizeof(use));
	prime[2]=1;
	num=0;
	for(int i = 2;i<MAXSIZE;i++)
	{
		if(prime[i])
		{
			num++;
			p[num]=i;
			for(int j = i*i;j<MAXSIZE;j+=i)
			{
				prime[j]=0;
			}
		}
		if(num>27)
			return;
	}
}
int comp(char* s1, char* s2)
{
	if(strlen(s1)!=strlen(s2))
		return -1;
	else
	{
		int sum1 = 0;
		int sum2=0;
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for(int i = 0;i<len1;i++)
			sum1*=p[(s1[i]-'a')+1];
		for(int i = 0;i<len2;i++)
			sum2*=p[(s2[i]-'a')+1];
		if(sum1==sum2)
			return 0;
		return -1;
	}
}
char ss[20][7];
int maxn;
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char str[7];
	int cnt=0;
	init();
	while(scanf("%s",str)!=EOF)
	{
		strcpy(ss[cnt++],str);
	}
	for(int i = 0;i<cnt;i++)
	{
		int sum = 1;
		int len = strlen(ss[i]);
		for(int j = 0;j<len;j++)
			sum*=p[(ss[i][j]-'a')+1];
		su[i]=sum;
		if(sum>maxn)
			maxn=sum;
	}
	for(int i = 0;i<cnt;i++)
	{
		if(use[i]==0)
		{
			use[i]=1;
			printf("%s ",ss[i]);
			for(int j = i+1;j<cnt;j++)
			{
				if(su[i]==su[j])
				{
					use[j]=1;
					printf("%s ",ss[j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

