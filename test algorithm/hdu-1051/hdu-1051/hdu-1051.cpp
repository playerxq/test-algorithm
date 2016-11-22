// hdu-1051.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct stick
{
    int l;
    int w;
}s[5000];

bool cmp(stick a,stick b)
{
    if(a.l<b.l)
        return true;
    else if(a.l>b.l)
        return false;
    else
        return a.w<b.w;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t,n,minute,ti,number;
    int mark[5000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>s[i].l>>s[i].w;
        sort(s,s+n,cmp);
        memset(mark,0,sizeof(mark));
        number=0;
        minute=0;
        int pl;
        while(number!=n)
        {
            for(int i=0;i<n;i++)
                if(!mark[i])
                {
                    pl=i;
                    minute++;
                    break;
                }
            for(int i=0;i<n;i++)
            {
                if(!mark[i]&&s[i].l>=s[pl].l&&s[i].w>=s[pl].w)
                {
                    mark[i]=1;
                    number++;
                    pl=i;
                }
            }
        }
        cout<<minute<<endl;
    }
    return 0;
}

