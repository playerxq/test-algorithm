// hdu-1030.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int m,n,cm,cn,rm,rn,lm,ln;    //c��ʾlevelͼ ��r��ʾrightͼ��l��ʾleftͼ
    while(scanf("%d%d",&m,&n)!=EOF)//
    {
        cm=(int)ceil(sqrt(m));//ceilΪ����ȡ��������math.h��
        cn=(int)ceil(sqrt(n));
        rm=(m-(cm-1)*(cm-1)-1)/2+1; //ȷ��m��rightͼ�е���һ��
        rn=(n-(cn-1)*(cn-1)-1)/2+1;
        lm=(cm*cm-m)/2+1;          //ȷ��m��leftͼ�е���һ��
        ln=(cn*cn-n)/2+1;
        int cnt=(int)(fabs(cm-cn)+fabs(lm-ln)+fabs(rm-rn));
        printf("%d\n",cnt);
    }
    return 0;
}

