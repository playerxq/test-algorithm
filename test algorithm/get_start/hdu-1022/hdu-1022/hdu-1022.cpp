// hdu-1022.cpp : 定义控制台应用程序的入口点。
//

//

#include "stdafx.h"
#include<iostream>  
#include<stack>  
#define max 100  
using namespace std;  
int main()  
{  
    stack<char>s;  
    int n,i,j,k,result[max];//n为列车个数， result数组用来表示结果，1表示进栈。0表示出  
    char str1[max],str2[max];//序列1和序列2  
    while(cin>>n>>str1>>str2)  
    {  
        j=0,i=0,k=1;  
        s.push(str1[0]); 
        result[0]=1;  
        while(i<n&&j<n)  
        {  
            if(s.size()&&s.top()==str2[j])  
            {
                j++;  
                s.pop();  
                result[k++]=0;  
            }  
            else  
            { 
                if(i==n)break;  
                s.push(str1[++i]);  
                result[k++]=1;  
            }  
        }  
        if(i==n)  
            cout<<"No."<<endl;  
        else  
        {
            cout<<"Yes."<<endl;  
            for(i=0; i<k; i++)  
                if(result[i])  
                    cout<<"in"<<endl;  
                else  
                    cout<<"out"<<endl;  
        }  
        cout<<"FINISH"<<endl;  
    }  
    return 0;  
} 



