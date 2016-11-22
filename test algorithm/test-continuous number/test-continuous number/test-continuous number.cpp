// test-continuous number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int n;
int x,k;
int dive[1000];
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(ncase)
			printf("\n\n");
		ncase++;
		printf("num is %d:\n",n);
		int j = 0;
		int ok = 0;
		x=k=0;
		dive[0]=1;j=1;
		n*=2;
		for(int i = 2;i<=sqrt((double)n);i++)
		{
			if(n%i==0)
			{
				dive[j++]=i;
				if(n/i!=i)
					dive[j++]=n/i;
			}
		}
		for(int i = j-1;i>=1;i--)
		{
			k = dive[i]-1;
			x=(((n/dive[i])-k)%2==0)?((n/dive[i])-k)/2:-1;
			if(x>0)
			{
				ok = 1;
				for(int i = x;i<=x+k;i++)
					printf("%d ",i);
				printf("\n");
			}
		}
		if(!ok)
			printf("-1\n");
	}
	return 0;
}

