// hdu-1015-backtract.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<cstring>
#define N 30
using namespace std;

char s[N],t[10],ans[10];
int target,n,a[N];
bool visited[N];

void work(int k)
{
    int temp,i;
    if(k==5)
    {
        temp=a[t[0]-'A']-(double)pow((double)(a[t[1]-'A']),2)+(double)pow((double)(a[t[2]-'A']),3)-(double)pow((double)(a[t[3]-'A']),4)+(double)pow((double)(a[t[4]-'A']),5);
        if(temp==target&&strcmp(t,ans)>0)
        {
            strcpy(ans,t);
        }
        return ;
    }
    for(i=0;i<n;i++)
    {
        if(!visited[s[i]-'A'])
        {
            t[k]=s[i];
            visited[s[i]-'A']=true;
            work(k+1);
            visited[s[i]-'A']=false;
        }
    }
}

int main()
{
    int i;
    for(i=0;i<26;i++) a[i]=i+1;
    while(cin>>target>>s&&(target||strcmp(s,"END")))
    {
        memset(visited,false,sizeof(visited));
        memset(ans,'\0',sizeof(ans));
        memset(t,'\0',sizeof(t));
        n=strlen(s);
        work(0);
        if(strlen(ans)==0) cout<<"no solution"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}

