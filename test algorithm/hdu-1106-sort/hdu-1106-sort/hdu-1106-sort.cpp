// hdu-1106-sort.cpp : 定义控制台应用程序的入口点。
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
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n,i,cnt;
    int b[1100];
    char a[1100],*p;
    while(~scanf("%s",a))
    {
        cnt=0;
        p=strtok(a,"5");
        while(p!=NULL)
        {
            b[cnt++]=atoi(p);
            p=strtok(NULL,"5");
        }
        qsort(b,cnt,4,cmp);
        printf("%d",b[0]);
        for(i=1;i<cnt;i++)
            printf(" %d",b[i]);
        putchar('\n');
    }
    return 0;
}

