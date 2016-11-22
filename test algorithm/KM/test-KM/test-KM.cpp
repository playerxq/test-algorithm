// test-KM.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int INF=(1<<31)-1;
const int maxn = 101;
int w[maxn][maxn];
int lx[maxn],ly[maxn]; //顶标  
int linky[maxn];  
int visx[maxn],visy[maxn];  
int slack[maxn];  
int nx,ny;
int dfs(int a)
{
	visx[a]=true;
	for(int i = 0;i<ny;i++)
	{
		if(visy[i]==1)
			continue;
		int t = lx[a]+ly[i]-w[a][i];//只有有边时才是有效值
		if(t==0)//在交错完备匹配中  类似匈牙利算法中找到增广路
		{
			visy[i]=1;
			if(linky[i]==-1||dfs(linky[i]))//去掉这条linky-i的边再尝试换一条边
			{
				linky[i]=a;
				return true;
			}
		}
		else if(slack[i]>t)//不在交错路径中
		{
			slack[i]=t;
		}
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
		for(i = 0; i < ny; i++)  
            slack[i] = INF; 
		while(1)
		{
			memset(visx,0,sizeof(visx));  
            memset(visy,0,sizeof(visy)); 
			if(dfs(x))//找到增广，退出  
                break; 
			//改变标值
			int d = INF;
			for(i = 0; i < ny; i++)//某条边的y不在交错子图中，取其slack值将其放入子图中
            {  
                if(!visy[i] && d > slack[i])  
                    d = slack[i];  
            }
			for(i = 0; i < nx; i++)//若原来的(x,y)边在交错图中则标值和不变，若x在y不在  则标值和-d，而d为slack最小值，故减d后标值和可以包含x+y与w(x,y)最接近的边
            {  
                if(visx[i])  
                    lx[i] -= d;  
            }  
            for(i = 0; i < ny; i++)  
            {  
                if(visy[i])  
                    ly[i] += d;  
                else  
                    slack[i] -= d;//被新包含进的边slack将为0  
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
	while(scanf("%d%d",&nx,&ny)!=EOF)
	{
		for(int i = 0;i<nx;i++)
		{
			for(int j = 0;j<ny;j++)
				scanf("%d",&w[i][j]);
		}
		printf("%d\n",KM());
	}
	return 0;
}

