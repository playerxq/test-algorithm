// hdu-1013.cpp : 定义控制台应用程序的入口点。
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
int n;
char str[1001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%s",str)!=EOF)
	{
		n = 0;
		if(str[0]=='0')
			break;
		for(int i = 0;i<strlen(str);i++)
			n+=str[i]-'0';
		while(n>9)
		{
			int t = n;
			n = 0;
			while(t)
			{
				n+=t%10;
				t = t/10;
			}
		}
		printf("%d\n",n);
	}
}

