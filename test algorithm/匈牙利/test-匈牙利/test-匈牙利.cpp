// test-匈牙利.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int map[105][105];
int used[105];
int flag[105];
int n;
int dfs(int a)
{
	for(int i = 1;i<=n;i++)
	{
		if(map[a][i]&&!used[i])
		{
			used[i]=1;
			if(!flag[i]||dfs(flag[i]))
			{
				flag[i]=a;
				return true;
			}
		}
	}
	return false;
}
int xiongyali()
{
	int num=0;
	for(int i = 1;i<=n;i++)
	{
		memset(used,0,sizeof(used));
		if(dfs(i))
			num++;
	}
	return num;
}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			scanf("%d",&map[i][j]);
	memset(flag,0,sizeof(flag));
	int num = xiongyali();
	printf("%d\n",num);
	return 0;
}

