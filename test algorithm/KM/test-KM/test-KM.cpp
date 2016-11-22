// test-KM.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int INF=(1<<31)-1;
const int maxn = 101;
int w[maxn][maxn];
int lx[maxn],ly[maxn]; //����  
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
		int t = lx[a]+ly[i]-w[a][i];//ֻ���б�ʱ������Чֵ
		if(t==0)//�ڽ����걸ƥ����  �����������㷨���ҵ�����·
		{
			visy[i]=1;
			if(linky[i]==-1||dfs(linky[i]))//ȥ������linky-i�ı��ٳ��Ի�һ����
			{
				linky[i]=a;
				return true;
			}
		}
		else if(slack[i]>t)//���ڽ���·����
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
                lx[i] = w[i][j]; //X���ϳ�ʼ��ֵΪ��Ȩ���ֵ
	for(int x = 0;x<nx;x++)
	{
		for(i = 0; i < ny; i++)  
            slack[i] = INF; 
		while(1)
		{
			memset(visx,0,sizeof(visx));  
            memset(visy,0,sizeof(visy)); 
			if(dfs(x))//�ҵ����㣬�˳�  
                break; 
			//�ı��ֵ
			int d = INF;
			for(i = 0; i < ny; i++)//ĳ���ߵ�y���ڽ�����ͼ�У�ȡ��slackֵ���������ͼ��
            {  
                if(!visy[i] && d > slack[i])  
                    d = slack[i];  
            }
			for(i = 0; i < nx; i++)//��ԭ����(x,y)���ڽ���ͼ�����ֵ�Ͳ��䣬��x��y����  ���ֵ��-d����dΪslack��Сֵ���ʼ�d���ֵ�Ϳ��԰���x+y��w(x,y)��ӽ��ı�
            {  
                if(visx[i])  
                    lx[i] -= d;  
            }  
            for(i = 0; i < ny; i++)  
            {  
                if(visy[i])  
                    ly[i] += d;  
                else  
                    slack[i] -= d;//���°������ı�slack��Ϊ0  
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

