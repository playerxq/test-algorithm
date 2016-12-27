// leetcode-205-异构字符串相等.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1!=len2)
            return false;
        map<char,char> mp;
		map<char,int> vis;
        for(int i = 0;i<len1;i++)
        {
            if((mp.count(s[i])>0)&&(mp[s[i]]==t[i]))
            {
                continue;
            }
            else if(mp.count(s[i])==0&&vis.count(t[i])==0)
			{
                mp[s[i]]=t[i];
				vis[t[i]]++;
			}
            else
                return false;
        }
        return true;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.isIsomorphic("ab","aa");
	return 0;
}

