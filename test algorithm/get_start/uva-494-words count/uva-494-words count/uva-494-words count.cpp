// uva-494-words count.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <ctype.h>
#include <iostream>
#include <string.h>
using namespace std;
#define max 5000
char s[max];
int main()
{
	int count = 0;
	bool first = 0;
    while(fgets(s,max,stdin)!=NULL)
	{
		count = 0;
		int len = strlen(s);
		for(int i = 0;i<len;i++)
		{
			if(isalpha(s[i])&&!first)
			{
				first = 1;
				count++;
			}
			if(!isalpha(s[i])&&first)
			{
				first = 0;
			}
		}
		printf("%d\n",count);
		memset(s,0,sizeof(s));
	}
	return 0;
}

