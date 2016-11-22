// hdu-1098-公式.cpp : 定义控制台应用程序的入口点。
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
int k;
int gcd(int a, int b)
{
	if(a<b)
	{
		int t = a;
		a = b;
		b = t;
	}
	if(!b)
		return a;
	else
	{
		while(b)
		{
			int t = a%b;
			a = b;
			b = t;
		}
		return a;
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&k)!=EOF)
	{
		if(k%10==0||k%10==5)
			printf("no\n");
		else
		{
			if(18%gcd(65,k)==0)
			{
				int i = 1;
				while((65*i-18)%k!=0)
				{
					i++;
				}
				printf("%d\n",(65*i-18)/k);
			}
			else
				printf("no\n");
		}
	}
}

