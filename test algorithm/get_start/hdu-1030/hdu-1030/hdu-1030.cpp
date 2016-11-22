// hdu-1030.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int m,n,cm,cn,rm,rn,lm,ln;    //c表示level图 ，r表示right图，l表示left图
    while(scanf("%d%d",&m,&n)!=EOF)//
    {
        cm=(int)ceil(sqrt(m));//ceil为向上取整函数“math.h”
        cn=(int)ceil(sqrt(n));
        rm=(m-(cm-1)*(cm-1)-1)/2+1; //确定m在right图中的那一层
        rn=(n-(cn-1)*(cn-1)-1)/2+1;
        lm=(cm*cm-m)/2+1;          //确定m在left图中的那一层
        ln=(cn*cn-n)/2+1;
        int cnt=(int)(fabs(cm-cn)+fabs(lm-ln)+fabs(rm-rn));
        printf("%d\n",cnt);
    }
    return 0;
}

