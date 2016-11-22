// hdu-1115-���������.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**

 

*�����������ڶ�����
* n����������Ϊ(xi,yi)������Ϊmi��������
*��X = ��( xi��mi ) / ��mi
*��Y = ��( yi��mi ) / ��mi
*������أ���ÿ�����������ͬ����
*��X = ��xi / n
*��Y = ��yi / n
*�������ֲ�����
*������أ��������ȵ����������ģ�
*��X = ( x0 + x1 + x2 ) / 3
*��Y = ( y0 + y1 + y2 ) / 3
*�������������ʽ��S = ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2 ;
*���ⲽ�裺1��������ηָ��n-2�������Σ����ݢ۹�ʽ��ÿ�������������
* 2�����ݢ���ÿ�����������ġ�
* 3�����ݢ���ö�������ġ�
**/
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
struct Point{
	double x,y;
};
double Area(Point p1,Point p2,Point p3)
{//��������������
	return ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))/2;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		Point p1,p2,p3;
		double gx,gy,sumarea;
		gx=gy=sumarea=0;
		scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
		for(int i=2;i<n;i++)
		{
			scanf("%lf%lf",&p3.x,&p3.y);
			double area=Area(p1,p2,p3);
			gx+=(p1.x+p2.x+p3.x)*area;//���ĳ�����Ȩֵ(���),��Ϊÿһ����Ҫ����3,��ҽԺ�������
			gy+=(p1.y+p2.y+p3.y)*area;
			sumarea+=area;
			p2=p3;
		}
		gx=gx/sumarea/3;//��Ķ��������
		gy=gy/sumarea/3;
		printf("%.2lf %.2lf\n",gx,gy);
	}
}

