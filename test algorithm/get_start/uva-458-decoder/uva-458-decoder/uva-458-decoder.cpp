// uva-458-decoder.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	char c;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			putchar(c);
		else
			putchar(c-7);
	}
	return 0;
}

