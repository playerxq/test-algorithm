// uva-10300-生态奖金.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int farmer = 0;
	int space,num_ani,x;
	int sum = 0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&farmer);
		for(int i = 0;i<farmer;i++)
		{
			scanf("%d%d%d",&space,&num_ani,&x);
			sum += space*x;
		}
		printf("%d\n",sum);
		sum = 0;
	}
	return 0;
}

