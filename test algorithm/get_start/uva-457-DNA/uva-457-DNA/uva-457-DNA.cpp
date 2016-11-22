// uva-457-DNA.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
int a[51][41];
int DNA[10];
int main()
{
	int t = 0;
	int i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		memset(DNA,0,sizeof(DNA));
		memset(a,0,sizeof(a));
		for (i=0;i<10;i++)
			 scanf("%d",&DNA[i]);
		for(i = 1;i<=40;i++)
			a[1][i] = 0;
		a[1][20] = 1;
		for(i = 2;i<=50;i++)
		{
			for(j = 1;j<=40;j++)
			{
				k = a[i-1][j];
				if(j>1) k+=a[i-1][j-1];
				if(j<40) k+=a[i-1][j+1];
				a[i][j] = DNA[k];
			}
		}
		for (i=1;i<=50;i++)
		{
			for (j=1;j<=40;j++)
				 switch (a[i][j])
				 {
					  case 1:printf(".");break;
					  case 2:printf("x");break;
					  case 3:printf("W");break;
					  case 0:printf(" ");break;
				}
			printf("\n");
		}
		if (t) printf("\n");
 
	}

	return 0;
}

