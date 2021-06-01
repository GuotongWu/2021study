/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lowbit(uint32_t n){
        return n & (-n);
    }
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            n -= lowbit(n);
            ++res;
        }
        return res;    
    }
};
// @lc code=end

