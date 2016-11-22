// hdu-1111-dfs.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int maxn=110;  
LL xr,xi,br,bi,num;  
LL flag,t;
LL ans[maxn];//保存枚举的ai
void dfs(LL rr,LL ii,LL step)
{
	if(step>100)
		return;
	if(flag)
		return;
	LL x,y,i;
	if(rr==0&&ii==0)
	{
		flag = 1;
		t = step;
		return;
	}
	for(i = 0;i*i<num;i++)
	{
		x=(rr-i)*br+ii*bi;  
        y=ii*br-(rr-i)*bi;
		ans[step]=i;  
        if(x%num==0&&y%num==0)//保证整除  
        dfs(x/num,y/num,step+1);  
        if(flag)return;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	LL T,i;
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d%I64d",&xr,&xi,&br,&bi);
		num=br*br+bi*bi;  
        flag=0;  
        dfs(xr,xi,0);  
        if(!flag)printf("The code cannot be decrypted.\n");  
        else  
        {  
            printf("%I64d",ans[t-1]);  
            for(i=t-2;i>=0;i--)  
            printf(",%I64d",ans[i]);  
            printf("\n");  
        }  
    }  
    return 0;
}

