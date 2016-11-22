// test.cpp : 定义控制台应用程序的入口点。
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
struct node
{
	int v;
	friend int operator < (const node& a, const node& b)
	{
		return a.v>b.v;
	}
};
bool cmp1(int a, int b)
{
	if(a<b)
		return true;
	else
		return false;
}
int cmp(const void* a, const void* b)
{
	int* _a = (int*) a;
	int* _b = (int*) b;
	if((*_a)<(*_b))
		return true;
	else
		return false;
}
int a[5];
int n;
priority_queue<node> q;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	n = 5;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
		node nn;
		nn.v = a[i];
		q.push(nn);
	}
	sort(a,a+n,cmp1);
	qsort(a,n,sizeof(a[0]),cmp);
	while(!q.empty())
	{
		node nx = q.top();
		q.pop();
		printf("%d",nx.v);
	}
}

