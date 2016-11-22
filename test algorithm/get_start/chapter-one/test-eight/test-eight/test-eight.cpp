// test-eight.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ctype.h>
#include <string>
#include <cstdio>
#define max 10
char s[max];
char buf[max+max];
int _tmain(int argc, _TCHAR* argv[])
{
	int j = 0;
	int count = 0;
	char c;
	scanf("%s",s);
	printf("word is %s\n",s);
	for(int i = 0;i<strlen(s);i++)
	{
		if(isalpha(s[i]))
		{
			bool ok = isupper(s[i]);
			s[i] = toupper(s[i]);
			
			if((s[i]>='A')&&(s[i]<='O'))
			{
				count = (s[i]-'A')%3+1;
				buf[j++] = ((s[i]-'A')/3)*3+(c = ((ok)?'A':'a'));
				buf[j++] = count + '0';
			}
			if((s[i]>='P')&&(s[i]<='S'))
			{
				count = s[i]-'P'+1;
				buf[j++] = (ok)?'P':'p';
				buf[j++] = count + '0';
			}
			if((s[i]>='T')&&(s[i]<='V'))
			{
				count = s[i]-'T'+1;
				buf[j++] = (ok)?'T':'t';
				buf[j++] = count + '0';
			}
			if((s[i]>='W')&&(s[i]<='Z'))
			{
				count = s[i]-'W'+1;
				buf[j++] = (ok)?'W':'w';
				buf[j++] = count + '0';
			}
		}
	}
	buf[j] = '\0';
	printf("input should be %s\n",buf);
	return 0;
}

