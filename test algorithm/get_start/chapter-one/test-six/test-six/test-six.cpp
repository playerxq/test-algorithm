// test-six.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <ctype.h>
#define max 100
FILE* fin;
FILE* fout;
char s[max][max];
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int i = 0;
	char e;
	fin = fopen("../../../input.txt","rb");
	fout = fopen("../../../output.txt","wb");
	fscanf(fin,"%d",&n);
	fscanf(fin,"%c",&e);
	fscanf(fin,"%c",&e);
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			fscanf(fin,"%c",&e);
			if(isalpha(e)||isdigit(e))
				s[i][j] = e;
		}
		fscanf(fin,"%c",&e);
		fscanf(fin,"%c",&e);
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			e = s[i][j];
			s[i][j] = s[j][i];
			s[j][i] = e;
		}
	}
	for(int i = n-1;i>=0;i--)
	{
		for(int j = 0;j<n;j++)
		{
			fprintf(fout,"%c",s[i][j]);
		}
		fprintf(fout,"\r\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

