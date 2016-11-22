// uva-414-合并.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
#define max 
char s[14][25];
int dif[14];
int main()
{
	int rows = 0;
	char c = 0;
	while(1)
	{
		scanf("%d",&rows);
		if(rows == 0)
			break;
		for(int i = 0;i<rows;i++)
		{
			int j = 0;
			do
			{
				scanf("%c",&c);
				if(c=='\n')
					continue;
				if((c=='X')||(c==' '))
				{
					s[i][j++] = c;
					continue;
				}
			}while(j<25);
		}
		int min = 30;
		memset(dif,0,sizeof(dif));
		for(int k = 0;k<rows;k++)
		{
			for(int l = 0;l<25;l++)
			{
				if(s[k][l]==' ')
					dif[k]++;
			}
			if(dif[k]<min)
				min = dif[k];
		}
		int sum = 0;
		for(int x = 0;x<rows;x++)
		{
			sum+=(dif[x]-min);
		}
		printf("%d\n",sum);
	}

	return 0;
}

