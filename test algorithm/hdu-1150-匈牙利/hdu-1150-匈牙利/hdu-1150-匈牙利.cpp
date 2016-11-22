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
	for(int i = 0;i<n;i++)
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
	for(int i = 0;i<m;i++)
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
    while(scanf("%d",&m),m)
    {
        scanf("%d%d",&n,&k);
        memset(map,0,sizeof(map));
        while(k--)
        {
            scanf("%d%d%d",&i,&u,&v);
            if(u>0&&v>0)map[u][v]=1;//初始状态为0，一开始0的边不要加
        }
        printf("%d\n",xiongyali());
    }
    return 0;
}

