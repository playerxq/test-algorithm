// hdu-1109-模拟退火.cpp : 定义控制台应用程序的入口点。
//
/*
刚开始的时候，在(0,0)到(X,Y)这个矩阵中随机取30个点，当作是起始的源点。然后设置步长（开始可能会比较大）
然后就可以开始扩散节点了了
遍历30个点，随机取周围的一个方向，然后点向这个方向偏移步长的大小，然后判断这个点是否合法，再判断这个点的答案是否更优（也就是离最近的地雷的距离是否比刚开始更大），如果更优，就更新以前的点，一直循环30次
所以这30个点现在答案都更优了，然后开始模拟退火，让步长减小
然后再循环上面的操作，直到步长小于一个精度
*/
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
#include <ctime>
using namespace std;
struct Node
{
	double x,y;
};
Node node[1505];
Node rand_pos[1505];
double dis[1505];
int X,Y,M;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-3;
double get_rand(double l, double r)
{
	return (rand()%10000)/10000.0*(r-l)+l;
}
double get_dis(Node a, Node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int judge(Node a)
{
	if(a.x>=0&&a.x<=X&&a.y>=0&&a.y<=Y)
		return 1;
	return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	srand((unsigned)time(NULL));
	while(T--)
	{
		scanf("%d%d%d",&X,&Y,&M);
		for(int i = 0;i<M;i++)
		{
			scanf("%lf%lf",&node[i].x,&node[i].y);
		}
		for(int i = 0;i<30;i++)
		{
			rand_pos[i].x = get_rand(1,X);
			rand_pos[i].y = get_rand(1,Y);
			dis[i]=INF;//最近地雷
			for(int j = 0;j<M;j++)
			{
				double temp = get_dis(rand_pos[i],node[j]);
				if(dis[i]>temp)
				{
					dis[i] = temp;
				}
			}
		}
		double step = max(X,Y);
		while(step>eps)
		{
			for(int i = 0;i<30;i++)//对每个随机人
			{
				for(int j = 0;j<30;j++)//模拟30次
				{
					double angl = get_rand(0,2*pi);
					Node nn;
					nn.x = rand_pos[i].x+step*cos(angl);
					nn.y = rand_pos[i].y+step*sin(angl);
					if(judge(nn))
					{
						double d = INF;
						for(int k = 0;k<M;k++)
						{
							double temp = get_dis(nn,node[k]);
							if(d>temp)
							{
								d = temp;
							}
						}
						if(d>dis[i])
						{
							dis[i]=d;
							rand_pos[i].x = nn.x;
							rand_pos[i].y = nn.y;
						}
					}
				}
			}
			step*=0.85;
		}
		int t = 1;
		for(int i = 0;i<M;i++)
		{
			if(dis[i]>=dis[t])
				t = i;
		}
		printf("The safest point is (%.1lf, %.1lf).\n", rand_pos[t].x, rand_pos[t].y);
	}
}

