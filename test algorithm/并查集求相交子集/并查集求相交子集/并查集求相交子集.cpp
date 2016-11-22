// 并查集求相交子集.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int p[50];
int used[27];
int res[11][27];
int top[11];
int find(int x)
{
	return (p[x]==x)?x:(p[x]=find(p[x]));
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int index = 0;
	int n;
	cin>>n;
	char r[6];
	for(int i = 1;i<=49;i++)
		p[i]=i;
	for(int i = 0;i<27;i++)
		used[i]=0;
	memset(res,0,sizeof(res));
	memset(top,0,sizeof(top));
	for(int i = 0;i<n;i++)
	{
		index++;
		cin>>(r);
		int l = strlen(r);
		for(int j = 0;j<l;j++)
		{
			if(find(index)!=find(r[j]-'a'+n+1))
				p[p[r[j]-'a'+n+1]]=index;
			used[r[j]-'a']=1;
		}
	}
		for(int i = 0;i<26;i++)
			if(used[i])
			{
				int group = find(i+n+1);
				res[group][top[group]++]=i;
			}
		for(int i = 0;i<=n;i++)
			if(top[i])
			{
				for(int j = 0;j<top[i];j++)
					printf("%c ",'a'+res[i][j]);
				printf("\n");
			}

	return 0;
}

