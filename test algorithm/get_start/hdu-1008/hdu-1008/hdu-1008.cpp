// hdu-1008.cpp : �������̨Ӧ�ó������ڵ㡣
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
int n,now,nextt,tt;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while((scanf("%d",&n)!=EOF)&&n)
	{
		now = 0;
		tt = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&nextt);
			if(nextt>=now)
				tt+=(nextt-now)*6+5;
			else
				tt+=(now-nextt)*4+5;
			now = nextt;
		}
		printf("%d\n",tt);
	}
}

