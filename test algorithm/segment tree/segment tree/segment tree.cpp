// segment tree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//���ѯ
int ql,qr;
int query(int o, int L, int R)
{
	int M = L+(R-L)/2;
	int ans = INF;
	if(ql<=L&&R<=qr)
		return minv[o];
	if(ql<=M) ans = min(ans,query(o*2,L,M));
	if(M<qr) ans = min(ans,query(o*2+1,M+1,R));
	return ans;
}
void update(int o, int L, int R)
{
	int M = L+(R-L)/2;
	if(L==R) minv[o]=v;
	else
	{
		if(p<=M)
			update(o*2,L,M);
		else
			update(o*2+1,M+1,R);
		minv[o]=min(minv[o*2],minv[o*2+1]);
	}
}
//�������
//�����
void maintain(int o, int L, int R)
{
	int lc = o*2;
	int rc = o*2+1;
	sumv[o]=minv[o]=maxv[o]=0;
	if(R>L)
	{
		sumv[o]=sumv[lc]+sumv[rc];
		minv[o]=min(minv[lc],minv[rc]);
		maxv[o]=min(maxv[lc],maxv[rc]);
	}
	minv[o]+=addv[o];
	maxv[o]+=addv[o];
	sumv[o]+=addv[o]*(R-L+1);
}
//����y1:y2������ֵ������ָ��ֵv
void update(int o, int L, int R)
{
	int lc = o*2,rc = o*2+1;
	if(y1<=L&&y2>=R)//ǡ�ð����ڵ�
		addv[o]+=v;
	else
	{
		int M = L+(R-L)/2;
		if(y1<=M)
			update(o*2,L,M);
		if(y2>M)
			update(o*2+1,M+1,R);
	}
	maintain(o,L,R);
}
int _min,_sum,_max;
void query(int o, int L, int R, int add)//addΪ���������ۼӺ�
{
	if(y1<=L&&R<=y2)
	{
		_sum+=sumv[o]+add*(R-L+1);
		_min=min(minv[o]+add,_min);
		_max=max(maxv[o]+add,_max);
	}
	else
	{
		int M = L+(R-L)/2;
		if(y1<=M) query(o*2,L,M,add+addv[o]);
		if(y2>M) query(o*2+1,M+1,R,add+addv[o]);
	}
}
//��������ֵ
void pushdown(int o)
{
	int lc = o*2,rc=o*2+1;
	if(setv[o]>=0)
	{
		setv[lc]=setv[rc]=setv[o];//���´���
		setv[o]=-1;
	}
}
void update(int o, int L, int R)
{
	int lc = o*2,rc=o*2+1;
	if(y1<=L&&R<=y2)//ǡ�ð���  ֱ������
	{
		setv[o]=v;//��addv����  ֱ������ֵ�������ۼ�
	}
	else
	{
		pushdown(o);//�����ߴ���  �����Ƿ�������´�����Ҫ������update��� û�����򲻻ᴫ��  ֻ��Ҫmaintain����
		int M = L+(R-L)/2;
		if(y1<=M)
			update(o*2,L,M);
		else
			maintain(lc,L,M);
		if(y2>M)
			update(o*2+1,M+1,R);
		else maintain(rc,M+1,R);
	}
	maintain(o,L,R);
}
void query(int o, int L , int R)
{
	if(setv[o]>=0)
	{
		_sum+=setv[o]*(min(R,y2)-max(L,y1)+1);
		_min=min(_min,setv[o]);
		_max = max(_max,setv[o]);
	}
	else if(y1<=L&&R<=y2)
	{
		_sum+=sumv[o];
		_min=min(_min,minv[o]);
		_max = max(_max,maxv[o]);
	}
	else
	{
		int M = L+(R-L)/2;
		if(y1<=M)
			query(o*2,L,M);
		if(y2>M)
			query(o*2+1,M+1,R);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

