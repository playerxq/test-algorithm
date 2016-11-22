// uva-694-3n+1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>

int main()
{
	long long a,b,n;
	int s = 0;
	int num = 0;
	while(scanf("%lld%lld",&a,&b)&&(a!=-1||b!=-1))
	{
		num++;
		s = 1;
		n = a;
		while(n>1)
		{
			if(n%2)  
                n=n*3+1;  
            else  
                n/=2;  
            if(n>b)break;  
            s++;
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",num,a,b,s); 
	}
	return 0;
}

