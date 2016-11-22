// rmq算法.cpp : 定义控制台应用程序的入口点。
//在线算法(ST)的RMQ算法：对于长度为n的数列A，回答若干询问RMQ（A,i,j）(i,j<=n)，返回数列A中下标在i，j之间的最小/大值。
//先DP预处理
//设A[i]是要求区间最值的数列，F[i, j]表示从第i个数起连续2^j个数中的最大值。（DP的状态）F[i,0]就等于A[i]
//F[i, j]=max（F[i，j-1], F[i + 2^(j-1)，j-1]）
//查询的区间为(i,j)  k=log2( j - i + 1)，则有：RMQ(A, i, j)=max{F[i , k], F[ j - 2 ^ k + 1, k]}

#include "stdafx.h"
#include <iostream>
using namespace std;
int maxsum[50][20];
int minsum[50][20];
void RMQ(int num)
{
	for(int j = 1;j<20;j++)//注意先j再i
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

