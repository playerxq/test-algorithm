// hdu-1112-模拟.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
bool key[109][109],s[11009][1009],visit[11009][1009];
int n,m;
int nm,mm;
bool in(int y)
{
	if(y>=0&&y<mm)
		return true;
	return false;
}
bool door(int x,int y)
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			if(key[i][j]&&s[i+x][j+y])
				return false;
	}
	return true;
}
int main()
{
	int cas,i,j,flag;
	char str[1009];
	scanf("%d",&cas);
	while(cas--)
	{
		memset(key,false,sizeof(key));
		memset(s,false,sizeof(s));
		memset(visit,false,sizeof(visit));
		scanf("%d%d",&n,&m);
		for(i=0; i<n; i++)
		{
			scanf("%s",str);
			for(j=0; j<m; j++)
			{
				if(str[j]=='#')
				key[i][j]=true;
			}
		}
		scanf("%d%d",&nm,&mm);
		nm+=n;
		for(i=n; i<nm; i++)
		{
			scanf("%s",str);
			for(j=0; j<mm; j++)
			{
				if(str[j]=='#')
				s[i][j]=true;
			}
		}
		for(i=0; i<mm; i++)//只有横向偏移时都是可行的且默认已访问
			visit[0][i]=true;
		for(i=1; i<nm; i++)//枚举key的左上角起点的偏移位置
		{
			flag=false;
			for(j=0; j<=mm-m; j++)
			{
				if(!visit[i][j]&&(visit[i-1][j]||(in(j-1)&&visit[i][j-1])||(in(j+1)&&visit[i][j+1])))//当前偏移未访问且纵向上一个偏移访问过或左右两个偏移访问过
				{
					if(door(i,j))//可以放置
					{
						flag=true;
						visit[i][j]=true;
						if(j>0&&!visit[i][j-1])
							j-=2;//下一轮j+1后变为vis[i][j-1] 相当于先考虑左边的偏移 再向右依次考虑
					}
				}
			}
			if(!flag)
				break;
		}
		if(i>=nm)
			printf("The key can fall through.\n");
		else
			printf("The key falls to depth %d.\n",i-1);
	}
	return 0;
}

