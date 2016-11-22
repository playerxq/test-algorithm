// hdu-1115-多边形重心.cpp : 定义控制台应用程序的入口点。
//
/**

 

*①质量集中在顶点上
* n个顶点坐标为(xi,yi)，质量为mi，则重心
*　X = ∑( xi×mi ) / ∑mi
*　Y = ∑( yi×mi ) / ∑mi
*　特殊地，若每个点的质量相同，则
*　X = ∑xi / n
*　Y = ∑yi / n
*②质量分布均匀
*　特殊地，质量均匀的三角形重心：
*　X = ( x0 + x1 + x2 ) / 3
*　Y = ( y0 + y1 + y2 ) / 3
*③三角形面积公式：S = ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2 ;
*做题步骤：1、将多边形分割成n-2个三角形，根据③公式求每个三角形面积。
* 2、根据②求每个三角形重心。
* 3、根据①求得多边形重心。
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
{//叉乘求三角形面积
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
			gx+=(p1.x+p2.x+p3.x)*area;//重心乘以其权值(面积),因为每一个都要除以3,所医院放在最后
			gy+=(p1.y+p2.y+p3.y)*area;
			sumarea+=area;
			p2=p3;
		}
		gx=gx/sumarea/3;//求的多边形重心
		gy=gy/sumarea/3;
		printf("%.2lf %.2lf\n",gx,gy);
	}
}

