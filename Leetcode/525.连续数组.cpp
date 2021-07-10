/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res;
        unordered_map<int,int> table;
        table[0] = 0;
        vector<int> prefix(n+1,0);
        for(int i=1; i<=n; ++i){
            nums[i-1]? prefix[i]=prefix[i-1]+1: prefix[i]=prefix[i-1]-1;
            if(table.find(prefix[i]) == table.end())
                table[prefix[i]] = i;
            else
                res = max(res, i-table[prefix[i]]);
        }
        return res;
    }
};
// @lc code=end

