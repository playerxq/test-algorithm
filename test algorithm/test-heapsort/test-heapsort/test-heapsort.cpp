// test-heapsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int a[10];
int res[10];
template<typename T>
void swap(T* a, int i, int j)
{
	T temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}
template<typename T>
void heapupdate(T* a, int size, int parent)
{
	int lchild=2*parent+1;
	int rchild=lchild+1;
	while(rchild<=size)
	{
		if(a[parent]<=a[lchild]&&a[parent]<=a[rchild])
			return;
		if(a[lchild]<=a[rchild])
		{
			swap(a,parent,lchild);
			parent=lchild;
		}
		else
		{
			swap(a,parent,rchild);
			parent=rchild;
		}
		lchild=2*parent+1;
        rchild=lchild+1;
	}
	if(lchild<=size)
	{
		if(a[lchild]<=a[parent])
		{
			swap(a,parent,lchild);
		}
	}
}
template<typename T>
void heapsort(T* a, int size)
{
	int k = 0;
	for(int i = size;i>=0;i--)
	{
		heapupdate(a,size,i);
	}
	while(size>=0)
	{
		res[k++]=a[0];
		swap(a,0,size);
		size--;
		heapupdate(a,size,0);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(int i = 0;i<10;i++)
		scanf("%d",&a[i]);
	heapsort(a,9);
	for(int i = 0;i<10;i++)
		printf("%d ",res[i] );
	return 0;
}

