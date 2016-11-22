// hdu-1109-ģ���˻�.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
�տ�ʼ��ʱ����(0,0)��(X,Y)������������ȡ30���㣬��������ʼ��Դ�㡣Ȼ�����ò�������ʼ���ܻ�Ƚϴ�
Ȼ��Ϳ��Կ�ʼ��ɢ�ڵ�����
����30���㣬���ȡ��Χ��һ������Ȼ������������ƫ�Ʋ����Ĵ�С��Ȼ���ж�������Ƿ�Ϸ������ж������Ĵ��Ƿ���ţ�Ҳ����������ĵ��׵ľ����Ƿ�ȸտ�ʼ���󣩣�������ţ��͸�����ǰ�ĵ㣬һֱѭ��30��
������30�������ڴ𰸶������ˣ�Ȼ��ʼģ���˻��ò�����С
Ȼ����ѭ������Ĳ�����ֱ������С��һ������
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
			dis[i]=INF;//�������
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
			for(int i = 0;i<30;i++)//��ÿ�������
			{
				for(int j = 0;j<30;j++)//ģ��30��
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

