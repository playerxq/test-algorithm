// hdu-1022.cpp : �������̨Ӧ�ó������ڵ㡣
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
    int n,i,j,k,result[max];//nΪ�г������� result����������ʾ�����1��ʾ��ջ��0��ʾ��  
    char str1[max],str2[max];//����1������2  
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



