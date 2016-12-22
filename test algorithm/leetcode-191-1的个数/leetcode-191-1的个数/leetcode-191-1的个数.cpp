// leetcode-191-1的个数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n) {
            n &= (n - 1);
            count++;
        }
        
        return count;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

