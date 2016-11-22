// test-quicksort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int a[10];
void swap(int i,int j)
{
	int temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}
int partion(int begin, int end)
{
	int la=a[end];
	int i = begin-1;
	int j;
	for(j = begin;j<=end-1;j++)
	{
		if(a[j]<la)
		{
			i++;
			swap(i,j);
		}
	}
	swap(i+1,end);
	return i+1;
}
void quicksort(int begin, int end)
{
	if(begin>end)
		return;
	int s=partion(begin,end);
	quicksort(begin,s-1);
	quicksort(s+1,end);
}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(int i =0;i<10;i++)
		scanf("%d",&a[i]);
	quicksort(0,9);
	for(int i =0;i<10;i++)
		printf("%d",a[i] );
	return 0;
}

