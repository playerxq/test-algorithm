// hdu-1177.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
struct Node
{
    int num;
    char time[15];
}students[150];
bool cmp(Node a,Node b)
{
    if(a.num>b.num) return 1;
    else if(a.num==b.num&&strcmp(a.time,b.time)<0)  return 1;
    else return 0;
}    
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,G,S,C,m;
    int num1,i;
    char time1[15];
    while(scanf("%d%d%d%d%d",&n,&G,&S,&C,&m))
    {
        if(n==0&&G==0&&S==0&&C==0&&m==0) break;
        for(i=0;i<n;i++)
        {
            scanf("%d%s",&students[i].num,&students[i].time); 
        }  
        num1=students[m-1].num;
        strcpy(time1,students[m-1].time); 
        sort(students,students+n,cmp);
        for(i=0;i<n;i++)
        {
            if(students[i].num==num1&&strcmp(students[i].time,time1)==0)  break;
        }
        i++;
        if(i<=G)  printf("Accepted today? I've got a golden medal :)\n");
        else if(i<=G+S)  printf("Accepted today? I've got a silver medal :)\n");
        else if(i<=G+S+C)  printf("Accepted today? I've got a copper medal :)\n");
        else  printf("Accepted today? I've got an honor mentioned :)\n");
    }  
    return 0;  
}
