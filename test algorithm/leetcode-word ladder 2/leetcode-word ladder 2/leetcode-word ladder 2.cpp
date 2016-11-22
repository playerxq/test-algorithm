// leetcode-word ladder 2.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<string> ve[2];
	vector<vector<string>> ans;  
	void dfs(map<string,vector<string>>& pre,vector<string>& path, string end)
	{
		if(pre[end].size()==0)
		{
			path.push_back(end);
			vector<string> ans_now = path;
			std::reverse(ans_now.begin(),ans_now.end());
			ans.push_back(ans_now);
			path.pop_back();
			return;
		}
		path.push_back(end);
		for(vector<string>::iterator iter = pre[end].begin();iter != pre[end].end(); ++iter)
			dfs(pre,path,(*iter));
		path.pop_back();
	}
    vector<vector<string>> findLadders(string start, string end, set<string> &dict) {
        map<string,vector<string>> pre;
		for(set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)  
            pre[*iter] = vector<string>();
		int previous = 1;
		int now = 0;
		ve[now].push_back(start);
		while(1)
		{
			now = now^1;
			previous = 1-now;
			for (vector<string>::iterator iter = ve[previous].begin(); iter != ve[previous].end(); ++iter)  
                dict.erase(*iter);  
            ve[now].clear(); 
			for(vector<string>::iterator iter = ve[previous].begin();iter != ve[previous].end(); ++iter)
			{
				for(int i = 0;i<(*iter).size();i++)
				{
					for(char c = 'a';c<='z';c++)
					{
						if((*iter)[i]==c)
							continue;
						else
						{
							string temp_w = (*iter);
							temp_w[i]=c;
							if(dict.find(temp_w)!=dict.end())
							{
								pre[(*iter)].push_back(temp_w);
								ve[now].push_back(temp_w);
							}
						}
					}
				}
			}
			if(ve[now].size()==0)
			{
				return ans;
			}
			for(vector<string>::iterator iter = ve[now].begin();iter != ve[now].end(); ++iter)
				if((*iter)==end)
					break;
		}
		vector<string> path;
		dfs(pre,path,end);
		return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

