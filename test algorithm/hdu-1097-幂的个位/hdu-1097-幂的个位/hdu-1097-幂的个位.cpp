// hdu-1097-幂的个位.cpp : 定义控制台应用程序的入口点。
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
int a,b;
int mod_exp(int a, int b, int c)
{
	int res = 1;
	int t = a%c;
	while(b)
	{
		if(b&1)
			res = res*t%c;
		t = t*t%c;
		b>>=1;
	}
	return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",mod_exp(a,b,10));
	}
}

