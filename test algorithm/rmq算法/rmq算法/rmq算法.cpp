// rmq�㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//�����㷨(ST)��RMQ�㷨�����ڳ���Ϊn������A���ش�����ѯ��RMQ��A,i,j��(i,j<=n)����������A���±���i��j֮�����С/��ֵ��
//��DPԤ����
//��A[i]��Ҫ��������ֵ�����У�F[i, j]��ʾ�ӵ�i����������2^j�����е����ֵ����DP��״̬��F[i,0]�͵���A[i]
//F[i, j]=max��F[i��j-1], F[i + 2^(j-1)��j-1]��
//��ѯ������Ϊ(i,j)  k=log2( j - i + 1)�����У�RMQ(A, i, j)=max{F[i , k], F[ j - 2 ^ k + 1, k]}

#include "stdafx.h"
#include <iostream>
using namespace std;
int maxsum[50][20];
int minsum[50][20];
void RMQ(int num)
{
	for(int j = 1;j<20;j++)//ע����j��i
	{
		for(int i = 1;i<=num;i++)
		{
			if(i+(1<<j)-1<=num)
			{
				maxsum[i][j]=max(maxsum[i][j-1],maxsum[i+2^(j-1)][j-1]);
				minsum[i][j]=min(minsum[i][j-1],minsum[i+2^(j-1)][j-1]);
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

