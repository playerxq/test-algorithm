// uva-10055-勇士.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	long our = 0;
	long opponent = 0;
	while(cin>>our>>opponent)
	{
		cout<<((our>opponent)?(our-opponent):(opponent-our))<<endl;
	}
	return 0;
}

