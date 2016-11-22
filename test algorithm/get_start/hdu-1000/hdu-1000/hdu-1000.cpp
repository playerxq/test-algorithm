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
int beg,end;
int A,B,n;
int f[100];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&A,&B,&n)!=EOF)
	{
		if(!A&&!B&&!n)
			break;
		memset(f,-1,sizeof(f));
		f[0] = f[1] = f[2] = 1;
		int flag = 0;
		for(int i = 3;i<=n&&!flag;i++)
		{
			f[i]=(A*f[i-1]+B*f[i-2])%7;
			for(int j = 2;j<=i-1;j++)
			{
				if(f[i]==f[j]&&f[i-1]==f[j-1])
				{
					beg = j;end = i;
					flag = 1;
					break;
				}
			}
		}
		if(flag)
			printf("%d\n",f[beg+(n-end)%(end-beg)]);
		else
			printf("%d\n",f[n]);
	}
}