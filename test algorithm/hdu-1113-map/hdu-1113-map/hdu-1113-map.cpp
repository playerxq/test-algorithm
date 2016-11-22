// hdu-1113-map.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
map<string,string> dir;
string s,t;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(cin>>s&&s!="XXXXXX")
	{
		t = s;
		sort(s.begin(),s.end());
		dir[t]=s;
	}
	while(cin>>s&&s!="XXXXXX")
	{
		bool flag = 0;
		t = s;
		sort(s.begin(),s.end());
		for(map<string,string>::iterator iter = dir.begin();iter != dir.end();iter++)
		{
			if(iter->second==s)
			{
				cout<<iter->first<<endl;
				flag = 1;
			}
		}
		if(!flag)
			cout << "NOT A VALID WORD\n";
		cout << "******\n";
	}
}

