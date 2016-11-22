#include "stdafx.h"
#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <queue>  
#include <stack>  
#include <algorithm>  
using namespace std;  
  
struct node  
{  
    int f,h,g;  
    int x,y;  
    char map[5][5];  
    friend bool operator< (const node &a,const node &b)  
    {  
        if(a.f==b.f)  
            return a.g<b.g;  
        return a.f>b.f;  
    }  
};  
  
char str[100];  
node start,nextx;  
int hashx[15];  
int pos[][2]= {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};  
bool vis[500000];  
char ans[500000];  
int pre[500000];  
int to[4][2] = {1,0,0,1,-1,0,0,-1};  
char to_c[10] = "drul";  
  
int check()//判断不可能的状况  逆序数 
{  
    int i,j,k;  
    int s[20];  
    int cnt = 0;  
    for(i = 0; i<3; i++)  
    {  
        for(j = 0; j<3; j++)  
        {  
            s[3*i+j] = start.map[i][j];  
            if(s[3*i+j] == 'x')  
                continue;  
            for(k = 3*i+j-1; k>=0; k--)  
            {  
                if(s[k] == 'x')  
                    continue;  
                if(s[k]>s[3*i+j])  
                    cnt++;  
            }  
        }  
    }  
    if(cnt%2)  
        return 0;  
    return 1;  
}  
  
int solve(node a)//康托  
{  
    int i,j,k;  
    int s[20];  
    int ans = 0;  
    for(i = 0; i<3; i++)  
    {  
        for(j = 0; j<3; j++)  
        {  
            s[3*i+j] = a.map[i][j];  
            int cnt = 0;  
            for(k = 3*i+j-1; k>=0; k--)  
            {  
                if(s[k]>s[3*i+j])  
                    cnt++;  
            }  
            ans = ans+hashx[i*3+j]*cnt;  
        }  
    }  
    return ans;  
}  
  
int get_h(node a)//得到H值  
{  
    int i,j;  
    int ans = 0;  
    for(i = 0; i<3; i++)  
    {  
        for(j = 0; j<3; j++)  
        {  
            if(a.map[i][j] == 'x')  
                continue;  
            int k = a.map[i][j]-'1';  
            ans+=abs(pos[k][0]-i)+abs(pos[k][1]-j);  //当前点到达其最终应该所在的位置花费的至少的步数
        }  
    }  
    return ans;  
}  
  
void bfs()  
{  
    memset(vis,0,sizeof(vis));  
    priority_queue<node> Q;  
    start.g = 0;  
    start.h = get_h(start);  
    start.f = start.h;  
    Q.push(start);  
    while(!Q.empty())  
    {  
        node a = Q.top();  
        Q.pop();  
        int k_s = solve(a);  
        for(int i = 0; i<4; i++)  
        {  
            nextx = a;  
            nextx.x+=to[i][0];  
            nextx.y+=to[i][1];  
            if(nextx.x < 0 || nextx.y < 0 || nextx.x>2 || nextx.y > 2)  
            continue;  
            nextx.map[a.x][a.y] = a.map[nextx.x][nextx.y];  
            nextx.map[nextx.x][nextx.y] = 'x';  
            nextx.g+=1;  
            nextx.h = get_h(nextx);  
            nextx.f = nextx.g+nextx.h;  
            int k_n = solve(nextx);  
            if(vis[k_n])  
                continue;  
            vis[k_n] = true;  
            Q.push(nextx);  
            pre[k_n] = k_s;  
            ans[k_n] = to_c[i];  
            if(k_n == 0)  
                return ;  
        }  
    }  
}  
  
int main()  
{  
    int i,j,len,x,y;  
    hashx[0] = 1;  
    for(i = 1; i<=9; i++)  
        hashx[i] = hashx[i-1]*i;  
    while(gets(str))  
    {  
        x = y = 0;  
        len = strlen(str);  
        for(i = 0; i<len; i++)  
        {  
            if(str[i]>='0' && str[i]<='9' || str[i]=='x')  
            {  
                start.map[x][y] = str[i];  
                if(start.map[x][y] == 'x')  
                {  
                    start.x = x;  
                    start.y = y;  
                }  
                y++;  
                if(y==3)  
                {  
                    y = 0;  
                    x++;  
                }  
            }  
        }  
        if(!check())  
        {  
            printf("unsolvable\n");  
            continue;  
        }  
        int sa = solve(start);  
        bfs();  
        stack<int> s;  
        int now = 0;  
        while(sa!=now)  
        {  
            s.push(ans[now]);  
            now = pre[now];  
        }  
        while(!s.empty())  
        {  
            putchar(s.top());  
            s.pop();  
        }  
        printf("\n");  
    }  
  
    return 0;  
}  