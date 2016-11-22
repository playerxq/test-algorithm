// uva-490-rotate sentence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string a[110];
int main()
{
	int i = 0;
	int j = 0;
	int max = 0;
	char c;
	while(getline(cin,a[i]))
	{
		if(max<a[i].length())
			max = a[i].length();
		i++;
	}
	int col = i;
	for(i = 0;i<max;i++)
	{
		for(j = col-1;j>=0;j--)
		{
			if(i<a[j].length())
				cout<<a[j][i];
			else
				cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}

