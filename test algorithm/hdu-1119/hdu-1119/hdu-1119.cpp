// hdu-1119.cpp : 定义控制台应用程序的入口点。
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
int res[1010];
int oper1[505];
int oper2[505];
int oper_temp1[505];
int oper_temp2[505];
char str[1010];
int temp[1010];
int len,res_len,temp_len;
int len1,len2;
void process_add()
{
	len = max(len1,len2);
	int c = 0;
	for(int i = 0;i<len;i++)
	{
		if(i<len1)
			c += oper1[i];
		if(i<len2)
			c+=oper2[i];
		res[i]=(c%10);
		c/=10;
	}
	while(c)
	{
		res[len++]=(c%10);
		c/=10;
	}
	res_len = max(len,len2+1);
	int space_num1 = res_len-len1;
	int space_num2 = res_len-len2-1;
	for(int i = 0;i<space_num1;i++)
		printf(" ");
	for(int i = len1-1;i>=0;i--)
		printf("%d",oper_temp1[i]);
	printf("\n");
	for(int i = 0;i<space_num2;i++)
		printf(" ");
	printf("+");
	for(int i = len2-1;i>=0;i--)
		printf("%d",oper_temp2[i]);
	printf("\n");
	for(int i = 0;i<res_len;i++)
		printf("-");
	printf("\n");
	int space_num = res_len-len;
	for(int i = 0;i<space_num;i++)
		printf(" ");
	for(int i = len-1;i>=0;i--)
		printf("%d",res[i]);
	printf("\n");
}
void process_sub()
{
	len = len1;
	int c = 0;
	int i = 0;
	for(;i<len2;i++)
	{
		if(oper1[i]<oper2[i])
		{
			oper1[i]+=10;
			oper1[i+1]-=1;
		}
		res[i]=oper1[i]-oper2[i];
	}
	for (; i < len; i++) 
	{  
        if (oper1[i] < 0) 
		{  
            oper1[i]+=10;
			oper1[i+1]-=1;  
        }  
        res[i] = oper1[i];  
    } 
	while(res[len-1]==0)
		len--;
	if (len == 0) len = 1;
	res_len = max(len1,max(len,len2+1));
	int space_num1 = res_len-len1;
	int space_num2 = res_len-len2-1;
	for(int i = 0;i<space_num1;i++)
		printf(" ");
	for(int i = len1-1;i>=0;i--)
		printf("%d",oper_temp1[i]);
	printf("\n");
	for(int i = 0;i<space_num2;i++)
		printf(" ");
	printf("-");
	for(int i = len2-1;i>=0;i--)
		printf("%d",oper_temp2[i]);
	printf("\n");
	for(int i = 0;i<res_len-max(len,len2+1);i++)
		printf(" ");
	for(int i = 0;i<max(len,len2+1);i++)
		printf("-");
	printf("\n");
	int space_num = res_len-len;
	for(int i = 0;i<space_num;i++)
		printf(" ");
	for(int i = len-1;i>=0;i--)
		printf("%d",res[i]);
	printf("\n");
}
void process_mul()
{
	len = len1+len2;
	for(int i = 0;i<len1;i++)
	{
		for(int j = 0;j<len2;j++)
		{
			res[i+j] += (oper1[i])*(oper2[j]);
		}
	}
	for(int i = 0;i<len;i++)
	{
		while(res[i]>=10)
		{
			res[i]-=10;
			res[i+1]++;
		}
	}
	while(len>1&&res[len-1]==0)
		len--;
	res_len = max(len1,max(len,len2+1));
	int space_num1 = res_len-len1;
	int space_num2 = res_len-len2-1;
	for(int i = 0;i<space_num1;i++)
		printf(" ");
	for(int i = len1-1;i>=0;i--)
		printf("%d",oper_temp1[i]);
	printf("\n");
	for(int i = 0;i<space_num2;i++)
		printf(" ");
	printf("*");
	for(int i = len2-1;i>=0;i--)
		printf("%d",oper_temp2[i]);
	printf("\n");
	if(len2==1)
	{
		for(int i = 0;i<res_len-max(len,len2+1);i++)
			printf(" ");
		for(int i = 0;i<max(len,len2+1);i++)
			printf("-");
		printf("\n");
		int space_num = res_len-len;
		for(int i = 0;i<space_num;i++)
			printf(" ");
		for(int i = len-1;i>=0;i--)
			printf("%d",res[i]);
		printf("\n");
	}
	else
	{
		for(int i = 0;i<len2;i++)
		{
			memset(temp,0,sizeof(temp));
			temp_len = 0;
			int c = 0;
			for(int j = 0;j<len1;j++)
			{
				temp[temp_len++] = (c+(oper2[i])*(oper1[j]))%10;
				c = (c+(oper2[i])*(oper1[j]))/10;
			}
			while(c)
			{
				temp[temp_len++] = c%10;
				c/=10;
			}
			while(temp_len>1&&temp[temp_len-1]==0)
				temp_len--;
			if(i==0)
			{
				int mm_len = max(len2+1,temp_len);
				int space_numx = res_len-mm_len;
				for(int i = 0;i<space_numx;i++)
					printf(" ");
				for(int i = 0;i<mm_len;i++)
					printf("-");
				printf("\n");
			}
			int space_numy = res_len-temp_len-i;
			for(int i = 0;i<space_numy;i++)
				printf(" ");
			for(int i = temp_len-1;i>=0;i--)
				printf("%d",temp[i]);
			printf("\n");
		}
		if(res_len==len)
		{
			for(int i = 0;i<res_len;i++)
				printf("-");
			printf("\n");
		}
		else
		{
			int space_numz = res_len-max(len,temp_len+len2-1);
			for(int i = 0;i<space_numz;i++)
				printf(" ");
			for(int i = 0;i<max(len,temp_len+len2-1);i++)
				printf("-");
			printf("\n");
		}
		int space_num = res_len-len;
		for(int i = 0;i<space_num;i++)
			printf(" ");
		for(int i = len-1;i>=0;i--)
			printf("%d",res[i]);
		printf("\n");
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	int cc  =0;
	scanf("%d",&T);
	while(T--)
	{
		int k = 0;
		memset(str,0,sizeof(str));
		scanf("%s",str);
		memset(res,0,sizeof(res));
		memset(oper1,0,sizeof(oper1));
		memset(oper2,0,sizeof(oper2));
		memset(oper_temp1,0,sizeof(oper_temp1));
		memset(oper_temp2,0,sizeof(oper_temp2));
		for(int i = 0;i<strlen(str);i++)
		{
			if(str[i]=='+'||str[i]=='-'||str[i]=='*')
			{
				k = i;
				break;
			}
		}
		for(int i = 0;i<k;i++)
		{
			oper1[i]=str[k-1-i]-'0';
			oper_temp1[i]=oper1[i];
		}
		len1 = k;
		for(int i = 0;i<strlen(str)-k-1;i++)
		{
			oper2[i]=str[strlen(str)-i-1]-'0';
			oper_temp2[i]=oper2[i];
		}
		len2 = strlen(str)-k-1;
		switch(str[k])
		{
		case '+':
			process_add();
			break;
		case '-':
			process_sub();
			break;
		case '*':
			process_mul();
			break;
		default:
			break;
		}
		printf("\n");
	}
}

