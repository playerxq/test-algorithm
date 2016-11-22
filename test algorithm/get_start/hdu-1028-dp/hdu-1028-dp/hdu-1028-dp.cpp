// hdu-1028-dp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
const int MAXN=130;
int dp[MAXN][MAXN];
//dp[i][j]��ʾ i ��ʾ�������������� j �ķ�����
int calc(int n,int m)
{
    
    if(dp[n][m]!=-1) return dp[n][m];
    
    
    if(n<1||m<1) return dp[n][m]=0;
    if(n==1||m==1) return dp[n][m]=1;
    if(n<m) return dp[n][m]=calc(n,n);
    if(n==m) return dp[n][m]=calc(n,m-1)+1;
    return dp[n][m]=calc(n,m-1)+calc(n-m,m);
    
}     
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    
    while(scanf("%d",&n)!=EOF)
      printf("%d\n",calc(n,n));
    return 0;
}

