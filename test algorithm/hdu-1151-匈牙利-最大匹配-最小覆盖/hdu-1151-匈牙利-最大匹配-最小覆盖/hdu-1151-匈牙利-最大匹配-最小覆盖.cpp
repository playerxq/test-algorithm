// hdu-1151-匈牙利-最大匹配-最小覆盖.cpp : 定义控制台应用程序的入口点。
// hdu-1150-匈牙利.cpp : 定义控制台应用程序的入口点。
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
int vis[110];
int map[110][110];
int n,m;
int linker[110];
int dfs(int cur)
{
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i]&&map[cur][i])
		{
			vis[i]=1;
			if(linker[i]==-1||dfs(linker[i]))
			{
				linker[i] = cur;
				return 1;
			}
		}
	}
	return 0;
}
int xiongyali()
{
	int res = 0;
	memset(linker,-1,sizeof(linker));
	for(int i = 1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			res++;
	}
	return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int k;
    int i,u,v;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		memset(map,0,sizeof(map));
		while(k--)
		{
			scanf("%d%d",&i,&u);
			map[i][u]=1;
		}
		printf("%d\n",n-xiongyali());
	}
    return 0;
}



