// hdu-1052.cpp : 定义控制台应用程序的入口点。
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
        int j=0,m=n;        //i表示田当前最快的马，j表示王当前最快的马,n-1表示田最慢的马，m-1表示王最慢的马 
        for(int i=0;i<n;++i)//sum表示田赢的场次，xx表示田输的场次 
        {
            if(a[i]>b[j])   //田最快的马大于王最快的马 
            {
                ++j; 
                ++sum;
                continue;   
            }
            else if(a[i]<b[j])  //田最快的马小于王最快的马，将田最慢的马和王比 
            {
                --n;
                --i;
                j++;
                xx++;
            }
            else if(a[i]==b[j]) //田最快的马等于王最快的马 
            {
                if(a[n-1]>b[m-1])//田最慢的马大于王最慢的马 
                {
                    --n;
                    --m;
                    --i;
                    ++sum;
                }
                else if(a[n-1]==b[j])//田最慢的马等于王最快的马 
                {
                    --i;
                    --n;
                    ++j;
                }
                else//田最慢的马小于王最快的马 
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

