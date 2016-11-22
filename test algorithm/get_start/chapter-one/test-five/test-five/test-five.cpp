// test-five.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ctype.h>
#define mod 1000
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	char s[9] = "12:34:56";
	int HH,MM,SS;
	char c;
	//s = "12:34:56";
	sscanf(s,"%d%c%d%c%d",&HH,&c,&MM,&c,&SS);
	printf("%d\n%d\n%d\n",HH,MM,SS);
	*/
	/*
	int i,a[101],n,max; 
	memset(a,sizeof(a),0);  
	while(scanf("%d",&n)==1) 
	{   a[n]++;   }   
	max=a[0];   
	for(i=1;i<101;i++)  
	{   
		if(a[i]>=max)   {    max=a[i];   }   
	}   
	for(i=0;i<101;i++) 
	{  
		if(a[i]==max)   {    printf("%d ",i);   }  
	}   
	printf("\n");
	*/
	char s[10000]; 
char buf[10000]; 


int i,m=0,n=0,sum=1;  
char ch;  
while(1)  
{   
scanf("%c",&ch);   
if(ch==EOF||ch=='\n')   
{    
break;    
}   
else    
{    
    s[m++]=ch;   
}   
}   
for(i=0;i<m;i++)  
{   
if(isdigit(s[i]))   
{    
buf[n++]=s[i]-'0';   
}   
}   
for(i=0;i<n;i++)  
{   
sum=sum*buf[i];   
}   
printf("%d\n",sum%mod); 
	return 0;
}

