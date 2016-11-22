// hdu-1011.cpp : 定义控制台应用程序的入口点。
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
double f[10];
void init()
{
	f[0]=1.0;
	for(int i = 1;i<10;i++)
	{
		f[i] = f[i-1]/i;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	int tmp = 2;
	double ee=2.5;
	init();
	for(int i = 3;i<=9;i++)
	{
		ee += f[i];
		printf("%d %.9lf\n",i,ee);
	}
}
