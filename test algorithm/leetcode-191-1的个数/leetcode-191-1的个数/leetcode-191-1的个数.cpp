// leetcode-191-1�ĸ���.cpp : �������̨Ӧ�ó������ڵ㡣
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

