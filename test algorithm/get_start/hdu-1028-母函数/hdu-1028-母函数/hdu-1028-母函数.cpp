// hdu-1028-母函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAXN 121
int c1[MAXN],c2[MAXN];//c1存放目前所有函数的乘积，c2存放两个函数的临时乘积
int maxn;
void mufun(int n)
{
    int i,j,k;
    for(i=0;i<=n;i++)
    {
        c1[i]=1;
    }
    for(k=2;k<=n;k++)
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j+i<=n;j+=k)
            {
                c2[i+j]+=c1[i];
            }    
        }
        for(i=0;i<=n;i++)
        {
            c1[i]=c2[i];
            c2[i]=0;
        }        
    }         
}
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    //while(cin>>n[0]>>n[1]>>n[2])
    {
      
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        mufun(n);
        printf("%d\n",c1[n]);   
    }
    return 0;    
}

