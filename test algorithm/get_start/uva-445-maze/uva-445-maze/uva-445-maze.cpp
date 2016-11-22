// uva-445-maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char c = 0;
	int sum = 0;
	while(EOF!=(c=getchar()))
	{
		if(isdigit(c))
			sum+=c-'0';
		else if(isupper(c)||c=='*'||c=='b')
		{
			for(int i = 0;i<sum;i++)
			{
				if(c=='b')
					printf(" ");
				else
					printf("%c",c);
			}
			sum = 0;
		}
		else 
			printf("\n");
	}
	return 0;
}

