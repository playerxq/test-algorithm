// hdu-1082-矩阵乘法次数.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int a[26][2],sum,tot;
int zhan[1000][2];
char str[1000];
int jin(int x)
{
	zhan[tot][0]=a[x][0];
	zhan[tot][1] = a[x][1];
	tot++;
	return 0;
}
int chu()
{
	if(zhan[tot-2][1]!=zhan[tot-1][0])
		return 1;
	sum+=zhan[tot-2][0]*zhan[tot-2][1]*zhan[tot-1][1];
	zhan[tot-2][1] = zhan[tot-1][1];
	tot--;
	return 0;
}
int n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	int a1,b1;
	char ch;
	for(int i = 0;i<n;i++)
	{
		getchar();
		scanf("%c %d %d",&ch,&a1,&b1);
		a[ch-'A'][0]=a1;
		a[ch-'A'][1]=b1;
	}
	while(scanf("%s",str)!=EOF)
	{
		sum = tot = 0;
		int flag = 0;
		int len = strlen(str);
		if(len == 1)
		{
			printf("0\n");
			continue;
		}
		for(int i = 0;i<len&&!flag;i++)
		{
			if(str[i]=='(')
				continue;
			if(str[i]==')')
			{
				flag = chu();
			}
			else
			{
				jin(str[i]-'A');
			}
			if(flag)
				break;
		}
		if(flag)
			printf("error\n");
		else
			printf("%d\n",sum);
	}
}

