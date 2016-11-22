// hdu-1141.cpp : 定义控制台应用程序的入口点。
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
int y_b[205],b;
void init()
{
	y_b[0] = 4;
	for(int i = 1970;i<=2160;i+=10)
	{
		y_b[(i-1960)/10] = y_b[(i-1960)/10-1]*2;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
			break;
		b = y_b[(n-1960)/10];
		double sum = 0;
		int i = 1;
		for(;;i++)
		{
			sum+=(double)(log((double)i)/log((double)2));
			if(sum>=b)
				break;
		}
		printf("%d\n",i-1);
	}

}

