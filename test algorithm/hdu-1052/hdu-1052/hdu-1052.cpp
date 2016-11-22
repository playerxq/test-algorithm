// hdu-1052.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
} 
int a[1005],b[1005];
int visiteda[1005],visitedb[1005];
int main(int argc, char *argv[])
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,sum,xx;
    while(cin>>n&&n)
    {
        int uu=n; 
        xx=0;
        sum=0;
        memset(visiteda,0,sizeof(visiteda));
        memset(visitedb,0,sizeof(visitedb));
        memset(a,0,sizeof(a));      
        memset(b,0,sizeof(b));
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        int j=0,m=n;        //i��ʾ�ﵱǰ������j��ʾ����ǰ������,n-1��ʾ����������m-1��ʾ���������� 
        for(int i=0;i<n;++i)//sum��ʾ��Ӯ�ĳ��Σ�xx��ʾ����ĳ��� 
        {
            if(a[i]>b[j])   //������������������� 
            {
                ++j; 
                ++sum;
                continue;   
            }
            else if(a[i]<b[j])  //��������С��������������������������� 
            {
                --n;
                --i;
                j++;
                xx++;
            }
            else if(a[i]==b[j]) //������������������� 
            {
                if(a[n-1]>b[m-1])//����������������������� 
                {
                    --n;
                    --m;
                    --i;
                    ++sum;
                }
                else if(a[n-1]==b[j])//��������������������� 
                {
                    --i;
                    --n;
                    ++j;
                }
                else//����������С���������� 
                {
                    --i;
                    --n;
                    ++j;
                    xx++;
                } 

            }


        }

        cout<<200*(sum-xx)<<endl; 

    } 

    return 0;
}

