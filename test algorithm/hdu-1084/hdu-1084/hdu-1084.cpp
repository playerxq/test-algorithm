// hdu-1084.cpp : 定义控制台应用程序的入口点。
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
int n;
struct pp
{
	int cnt;
	int tt;
	int id;
	int ss;
};
pp a[101];
int score[10] = {100,95,90,85,80,75,70,65,60,50};
int ct[6];
int cur[6];
int cmp(pp p1, pp p2)
{
	if(p1.cnt!=p2.cnt)
		return p1.cnt>p2.cnt;
	return p1.tt<p2.tt;
}
int cmp1(pp p1, pp p2)
{
	return p1.id<p2.id;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
			break;
		memset(a,0,sizeof(a));
		memset(ct,0,sizeof(ct));
		memset(cur,0,sizeof(cur));
		for(int i = 0;i<n;i++)
		{
			a[i].id = i+1;
			scanf("%d",&(a[i].cnt));
			ct[a[i].cnt]++;
			int h,m,s;
			scanf("%d:%d:%d",&h,&m,&s);
			a[i].tt = h*3600+m*60+s;
		}
		sort(a,a+n,cmp);
		for(int i = 0;i<n;i++)
		{
			if(a[i].cnt==5)
			{
				a[i].ss = 100;
			}
			else if(a[i].cnt==0)
			{
				a[i].ss = 50;
			}
			else if(i>0&&a[i].cnt!=a[i-1].cnt)
			{
				a[i].ss = score[2*(5-a[i].cnt)-1];
			}
			else if(i>0&&a[i].cnt==a[i-1].cnt&&cur[a[i].cnt]+1<=(ct[a[i].cnt]/2))
			{
				a[i].ss = score[2*(5-a[i].cnt)-1];
			}
			else if(i>0&&a[i].cnt==a[i-1].cnt&&cur[a[i].cnt]+1>(ct[a[i].cnt]/2))
			{
				a[i].ss = score[2*(5-a[i].cnt)];
			}
			else
			{
				a[i].ss = score[2*(5-a[i].cnt)-1];
			}
			cur[a[i].cnt]++;
		}
		sort(a,a+n,cmp1);
		for(int i = 0;i<n;i++)
			printf("%d\n",a[i].ss);
		printf("\n");
	}
}

