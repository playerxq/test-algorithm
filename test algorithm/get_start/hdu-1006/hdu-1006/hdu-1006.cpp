// hdu-1006.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct qujian
{
    double l,r;
};    
double D;
qujian solve(double a,double b)//�ⷽ�� D<=a*x+b<=360-D ,���Һ� [0,60] ȡ����
{
    qujian p;
    if(a>0)
    {
        p.l=(D-b)/a;
        p.r=(360-D-b)/a;
    }    
    else
    {
        p.l=(360-D-b)/a;
        p.r=(D-b)/a;
    }    
    if(p.l<0)p.l=0;
    if(p.r>60)p.r=60;
    if(p.l>=p.r)  p.l=p.r=0;
    return p;
}     
qujian jiao(qujian a,qujian b)
{
    qujian p;
    p.l=max(a.l,b.l);
    p.r=min(a.r,b.r);
    if(p.l>=p.r) p.l=p.r=0;
    return p;
}    
/*
   hh=30*h+m/2+s/120;
   mm=6*m+s/10;
   ss=6*s;
   D<=|hh-mm|<=360-D;
   D<=|hh-ss|<=360-D;
   D<=|mm-ss|<=360-D;
   hh-mm=
*/
double happytime(int h,int m)//���� h ʱ��m �� �������������
{
    double a,b;
    qujian s[3][2];
    qujian s1;
    
    //�ⷽ�� D<=|hh-mm|<=360-D 
    //hh=30*h+m/2+s/120;
    //mm=6*m+s/10;
    a=1.0/120-0.1;
    b=30*h+m/2.0-6*m;
    s[0][0]=solve(a,b);
    s[0][1]=solve(-a,-b);
    
    //�ⷽ��  D<=|hh-ss|<=360-D 
    //hh=30*h+m/2+s/120;
    //ss=6*s;
    a=1.0/120-6.0;
    b=30*h+m/2.0;
    s[1][0]=solve(a,b);
    s[1][1]=solve(-a,-b);
    
    //�ⷽ��  D<=|mm-ss|<=360-D 
    //mm=6*m+s/10;
    //ss=6*s;
    a=0.1-6;
    b=6*m;
    s[2][0]=solve(a,b);
    s[2][1]=solve(-a,-b);
    
    double res=0;
    //�������䣬ѡ����ȡ������
    //��Ϊ����ֵ��ʽ�ӵõ�����������Ҫ������������ͬ���ʽ������Ҫ�������������� 
    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++)
         for(int k=0;k<2;k++)
         {
             s1=jiao(jiao(s[0][i],s[1][j]),s[2][k]);
             res+=s1.r-s1.l;
         }    
    return res;
}     

int main()
{
    while(scanf("%lf",&D))
    {
        if(D==-1) break;
        double res=0;
        int h,m;
        for(h=0;h<12;h++)
        {
            for(m=0;m<60;m++)
            {
                res+=happytime(h,m);
            }    
        }    
        printf("%.3lf\n",res*100.0/(60*60*12));    
    }    
    return 0;
}

