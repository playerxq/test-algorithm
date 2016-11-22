// hdu-1014.cpp : 定义控制台应用程序的入口点。
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
int st,md;
int k;
int gcd(int a, int b)
{
	if(a<b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while(b)
	{
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&st,&md)!=EOF)
	{
		printf("%10d%10d    ",st,md);
		k = gcd(st,md);
		if(k!=1)
			printf("Bad Choice\n\n");
		else
			printf("Good Choice\n\n");
	}
}

