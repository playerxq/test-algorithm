// shell-sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int a[10]={2,6,8,5,4,9,7,3,1,0};
void shell_sort()
{
	int div = 5;
	while(div>=1)
	{
		for(int i = div;i<10;i++)
		{
			int j = i;
			for(;j-div>=0&&a[j]<a[j-div];j-=div)
			{
				int temp = a[j-div];
				a[j-div]=a[j];
				a[j]=temp;
			}
		}
		div/=2;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	shell_sort();
	for(int i = 0;i<10;i++)
		printf("%d\n",a[i]);
	getchar();
	return 0;
}

