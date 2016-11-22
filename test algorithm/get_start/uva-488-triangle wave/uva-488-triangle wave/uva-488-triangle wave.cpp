// uva-488-triangle wave.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int a ,b;
	int i,j,k;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		cin>>a>>b;
		for(i = 0;i<b;i++)
		{
			for(j = 1;j<=a;j++)
			{
				for(k = 1;k<=j;k++)
					cout<<j;
				cout<<endl;
			}
			for(j = a-1;j>=1;j--)
			{
				for(k = 1;k<=j;k++)
					cout<<j;
				cout<<endl;
			}
			if(i!=b-1)
				cout<<endl;
		}
		if(n)
			cout<<endl;
	}
	return 0;
}

