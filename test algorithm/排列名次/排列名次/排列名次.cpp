// 排列名次.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int n;
int a[15];
int b[15];
int f[15];
void init()
{
	f[0]=f[1]=1;
	for(int i = 2;i<15;i++)
		f[i]=f[i-1]*i;
}
int rank(int a[], int n)//计算排列的名次 从0开始
{
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		sum+=(a[i]-1)*f[n-1-i];
		for(int j = i+1;j<n;j++)
		{
			if(a[j]>a[i])
				a[j]--;
		}
	}
	return sum;
}
int next_perm(int a[], int n)//计算下一个排列
{
	int i = n-2;
	while(i>=0&&a[i]>a[i+1])
		i--;
	if(i<0)
		return 0;
	else
	{
		int j = n-1;
		while(a[j]<a[i])
			j--;
		int t = a[i];
		a[i]=a[j];
		a[j]=t;
		//reverse a[i+1]:a[n-1]
		int index = 0;
		for(int k = n-1;k>=i+1;k--)
			b[index++]=a[k];
		index = 0;
		for(int k = i+1;k<n;k++)
			a[k]=b[index++];
		for(int i = 0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return 1;
	}
}
void rank_2_perm(int r,int n)//由排名计算排列
{
	a[n-1]=1;
	for(int i = n-2;i>=0;i--)
	{
		int g = r%f[n-i]/f[n-i-1];
		a[i]=g+1;
		for(int j = i+1;j<n;j++)
			if(a[j]>=a[i])
				a[j]++;
	}
	for(int i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
class Solution {
public:
	int f[15];
	void init()
	{
		f[0]=f[1]=1;
		for(int i = 2;i<15;i++)
			f[i]=f[i-1]*i;
	}
    string getPermutation(int n, int k) {
        init();
		k--;
		int* a = new int [n];
		for(int i = 0;i<n;i++)
			a[i] = 0;
		a[n-1] = 1;
		for(int i = n-2;i>=0;i--)
		{
			int g = k%f[n-i]/f[n-i-1];
			a[i] = g+1;
			for(int j = i+1;j<n;j++)
			if(a[j]>=a[i])
				a[j]++;
		}
		string s;
		for(int i = 0;i<n;i++)
			s.push_back('0'+a[i]);
		return s;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",rank(a,n));
		//while(next_perm(a,n));
		for(int i = 23;i>=0;i--)
			rank_2_perm(i,5);
	}
	Solution ss;
	ss.getPermutation(3,5);
}

