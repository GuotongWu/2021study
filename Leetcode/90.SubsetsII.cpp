/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int curr, vector<int> nums){
        if(curr = nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(curr, )
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
    } 
};
// @lc code=end

