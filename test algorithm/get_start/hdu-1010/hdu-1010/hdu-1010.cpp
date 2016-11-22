// hdu-1010.cpp : 定义控制台应用程序的入口点。
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
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
struct Node
{
	int x,y,ss,dd;
};
Node st,ed;
int T,N,M;
int maze[10][10];
int ok(int x, int y)
{
	if(x<=N&&x>=1&&y<=M&&y>=1&&maze[x][y]==0)
		return 1;
	return 0;
}
int dfs(Node cur)
{
	if(cur.x==ed.x&&cur.y==ed.y&&cur.ss==T)
		return 1;
	if(cur.ss>=T)
		return 0;
	if(ed.x-cur.x+ed.y-cur.y>T-cur.ss)
		return 0;
	for(int i = 0;i<4;i++)
	{
		int xx = cur.x+dir[i][0];
		int yy = cur.y+dir[i][1];
		if(ok(xx,yy))
		{
			maze[cur.x][cur.y]=1;
			Node nx;
			nx.x = xx;
			nx.y = yy;
			nx.ss = cur.ss+1;
			if(dfs(nx))
				return 1;
			maze[cur.x][cur.y]=0;
		}
	}
	return 0;
}
char sss[8];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&N,&M,&T)!=EOF)
	{
		if(N==0&&M==0&&T==0)
			break;
		memset(maze,-1,sizeof(maze));
		for(int i = 1;i<=N;i++)
		{
			scanf("%s",sss);
			for(int j = 1;j<=M;j++)
			{
				if(sss[j-1]=='.')
					maze[i][j]=0;
				else if(sss[j-1]=='X')
					maze[i][j]=-1;
				else if(sss[j-1]=='S')
				{
					st.x = i;
					st.y = j;
					st.ss = 0;
					maze[i][j]=1;
				}
				else
				{
					ed.x = i;
					ed.y = j;
					maze[i][j]=0;
				}
			}
		}
		if((ed.x-st.x+ed.y-st.y>T||(ed.x+st.x+ed.y+st.y+T)%2==1))
			printf("NO\n");
		else if(dfs(st))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

