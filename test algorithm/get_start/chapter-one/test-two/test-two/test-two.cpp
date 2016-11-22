// test-two.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#define MAX 10
int a[MAX][MAX];
FILE* fin;
FILE* fout;
int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	int x,y;
	fin = fopen("../../../input.txt","rb");
	fout = fopen("../../../output.txt","wb");
	fscanf(fin,"%d",&n);
	int tot = 0;
	memset(a,0,sizeof(a));
	a[0][n-1] = tot = 1;
	x = 0;
	y = n-1;
	while(tot<n*n)
	{
		while((x+1<n)&&!a[x+1][y]) a[++x][y] = ++tot;
		while((y-1>=0)&&!a[x][y-1]) a[x][--y] = ++tot;
		while((x-1>=0)&&!a[x-1][y]) a[--x][y] = ++tot;
		while((y+1<n)&&!a[x][y+1]) a[x][++y] = ++tot;
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			fprintf(fout,"%3d\n",a[i][j]);
		}
		fprintf(fout,"\r\n");
		//fflush(fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

