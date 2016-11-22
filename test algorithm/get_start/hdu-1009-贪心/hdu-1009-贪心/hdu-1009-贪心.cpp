// hdu-1009-贪心.cpp : 定义控制台应用程序的入口点。
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
#define N 1005
struct warehouse_node{  
    double jj,ff,uu;  
};  
warehouse_node HH[N];
int n;
double tt,m;
bool cmp(struct warehouse_node a,struct warehouse_node b){  
    if (a.uu>=b.uu)  
        return true;  
    else return false;  
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%lf%d",&m,&n)!=EOF)
	{
		if(m==-1&&n==-1)
			break;
		for(int i = 0;i<n;i++)
		{
			scanf("%lf%lf",&HH[i].jj,&HH[i].ff);
			HH[i].uu = HH[i].jj/HH[i].ff;
		}
		sort(HH,HH+n,cmp);
		tt = 0;
		for(int i = 0;i<n&&m;i++)
		{
			if(m>=HH[i].ff)
			{
				m = m-HH[i].ff;
				tt+=HH[i].jj;
			}
			else
			{
				tt+=m/HH[i].ff*HH[i].jj;
				m = 0;
			}
		}
		printf("%.3lf\n",tt);
	}
	return 0;
}

