// test-baidustart2006-seat.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int INF=(1<<31)-1;
const int maxn = 305;
int m,n;
int a[maxn];
int w[maxn][maxn];
int temp[maxn][maxn]; 
int lx[maxn],ly[maxn]; //顶标  
int linky[maxn];  
int vistx[maxn],visty[maxn];  
int slack[maxn];  
int nx,ny;
int dfs(int a)
{
	vistx[a]=1;
	for(int i = 0;i<ny;i++)
	{
		if(visty[i]==1)
			continue;
		int t = lx[a]+ly[i]-w[a][i];
		if(t==0)
		{
			visty[i]=1;
			if(linky[i]==-1||dfs(linky[i]))
			{
				linky[i]=a;
				return true;
			}
		}
		else if(slack[i]>t)
			slack[i]=t;
	}
	return false;
}
int KM()
{
	int i,j;  
    memset(linky,-1,sizeof(linky));  
    memset(ly,0,sizeof(ly));  
    for(i = 0; i < nx; i++)  
        for(j = 0,lx[i] = -INF; j < ny; j++)  
            if(w[i][j] > lx[i])  
                lx[i] = w[i][j]; //X集合初始标值为边权最大值
	for(int x = 0;x<nx;x++)
	{
		for(int i = 0;i<ny;i++)
			slack[i]=INF;
		while(1)
		{
			memset(vistx,0,sizeof(vistx));  
            memset(visty,0,sizeof(visty)); 
			if(dfs(x))//找到增广，退出  
                break; 
			int d = INF;
			for(int i = 0;i<ny;i++)
			{
				if(d>slack[i]&&!visty[i])
					d = slack[i];
			}
			for(int i = 0;i<nx;i++)
			{
				if(vistx[i])
					lx[i]-=d;
			}
			for(int i = 0;i<ny;i++)
			{
				if(visty[i])
					ly[i]+=d;
				else
					slack[i]-=d;
			}
		}
	}
	int result = 0;  
    for(i = 0; i < ny; i++)  
        result += w[linky[i]][i];  
    return result; 
}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,num;  
    while(scanf("%d%d",&m,&n)!=EOF)  
    {  
        for(i=0;i<m;i++)  
            scanf("%d",&a[i]);  
        for(i=0;i<n;i++)  
            for(j=0;j<m;j++)  
                scanf("%d",&temp[i][j]);  
        for(i=0;i<n;i++)  
        {  
            num=0;  
            for(j=0;j<m;j++)  
            {  
                for(k=1;k<=a[j];k++)  
                {    
                    w[i][num++]=temp[i][j];  
                }  
            }  
        }
		nx = n;ny=num;
		printf("%d\n",KM());
	}
	return 0;
}

