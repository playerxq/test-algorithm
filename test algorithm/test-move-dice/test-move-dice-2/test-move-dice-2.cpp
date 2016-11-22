// test-move-dice-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int a[10];
int b[10];
int a1[10];
int b1[10];
int c[10];
int num,num1;
int n1,n2;
queue<unsigned int> q;
unsigned int src,des;
int _0[2]={1,3};
int _1[3]={0,2,4};
int _2[2]={1,5};
int _3[2]={0,4};
int _4[4]={1,3,5,7};
int _5[3]={2,4,8};
int _6[2]={3,7};
int _7[3]={4,6,8};
int _8[2]={5,7};
unsigned long long used[14000000];
unsigned int pow(int i)
{
	int ret = 1;
	if(i==0)
		return 1;
	for(int j = 1;j<=i;j++)
	{
		ret*=10;
	}
	return ret;
}
int get_reverse(int* p, int begin, int end)
{
	if(begin==end)
	{
		return 0;
	}
	int mid = begin+(end-begin)/2;
	int n1 = get_reverse(p,begin,mid);
	int n2 = get_reverse(p,mid+1,end);
	int k = begin;
	int nu = 0;
	int i,j;
	for(i = begin,j=mid+1;i<=mid&&j<=end;)
	{
		if(p[i]<=p[j])
		{
			c[k++]=p[i];
			i++;
		}
		else
		{
			nu+=mid-i+1;
			c[k++]=p[j];
			j++;
		}
	}
	while(i<=mid)
	{
		c[k++]=p[i];
		i++;
	}
	while(j<=end)
	{
		c[k++]=p[j];
		j++;
	}
	for(int i = begin;i<=end;i++)
		p[i]=c[i];
	return n1+n2+nu;
}
int get_0(unsigned int ss)
{
	int i = 0;
	while(ss)
	{
		if(ss%10==0)
			return i;
		i++;
		ss=ss/10;
	}
	return 8;
}
int get_i(unsigned int ss, int i)
{
	int s = -1;
	i = 8-i;
	while(i>=0)
	{
		s=ss%10;
		ss/=10;
		i--;
	}
	return s;
}
int ok(unsigned int ss)
{
	unsigned int x = ss%64;
	unsigned int y = ss/64;
	unsigned int t = used[y]>>x;
	if((used[y]>>x)&(unsigned long long)1)
		return 0;
	return 1;
}
void set_used(unsigned int ss)
{
	unsigned int x = ss%64;
	unsigned int y = ss/64;
	unsigned long long t = ((unsigned long long)1<<x);
	used[y]=used[y]|(t);
}
int bfs()
{
	memset(used,0,sizeof(used));
	q.push(src);
	set_used(src);
	q.push(0);
	unsigned int temp,temp_swap;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp==0)
		{
			num++;
			q.push(0);
			continue;
		}
		int index=8-get_0(temp);
		switch(index)
		{
		case 0:
			for(int i = 0;i<2;i++)
			{
				temp_swap = temp-get_i(temp,_0[i])*(pow(8-_0[i])-pow(8));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 1:
			for(int i = 0;i<3;i++)
			{
				temp_swap = temp-get_i(temp,_1[i])*(pow(8-_1[i])-pow(7));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 2:
			for(int i = 0;i<2;i++)
			{
				temp_swap = temp-get_i(temp,_2[i])*(pow(8-_2[i])-pow(6));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 3:
			for(int i = 0;i<2;i++)
			{
				temp_swap = temp-get_i(temp,_3[i])*(pow(8-_3[i])-pow(5));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 4:
			for(int i = 0;i<4;i++)
			{
				temp_swap = temp-get_i(temp,_4[i])*(pow(8-_4[i])-pow(4));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 5:
			for(int i = 0;i<3;i++)
			{
				temp_swap = temp-get_i(temp,_5[i])*(pow(8-_5[i])-pow(3));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 6:
			for(int i = 0;i<2;i++)
			{
				temp_swap = temp-get_i(temp,_6[i])*(pow(8-_6[i])-pow(2));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 7:
			for(int i = 0;i<3;i++)
			{
				temp_swap = temp-get_i(temp,_7[i])*(pow(8-_7[i])-pow(1));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		case 8:
			for(int i = 0;i<2;i++)
			{
				temp_swap = temp-get_i(temp,_8[i])*(pow(8-_8[i])-pow(0));
				if(temp_swap==des)
				{
					return num+1;
				}
				if(ok(temp_swap))
				{
					q.push(temp_swap);
					set_used(temp_swap);
				}
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int k = 0;
	for(int i = 1;i<=9;i++)
	{
		scanf("%d",&a[i]);
		if(a[i])
			a1[k++]=a[i];
	}
	k = 0;
	for(int i = 1;i<=9;i++)
	{
		scanf("%d",&b[i]);
		if(b[i])
			b1[k++]=b[i];
	}
	n1=get_reverse(a1,0,7);
	n2=get_reverse(b1,0,7);
	if(n1%2!=n2%2)
		printf("no path\n");
	else
	{
		src=des=0;
		for(int i = 1;i<=9;i++)
		{
			src=src*10+a[i];
			des=des*10+b[i];
		}
		if(src==des)
			printf("step is 0\n");
		else
		{
			int r = bfs();
			printf("step is %d\n",r);
		}
	}
	return 0;
}

