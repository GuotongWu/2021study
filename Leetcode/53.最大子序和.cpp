/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dynamic-progranmming
        int pre = nums[0];
        int max = nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(pre+nums[i] > nums[i])
                pre += nums[i];
            else
                pre = nums[i];
            if(pre > max)
                max = pre;
        }
        return max;
    }
};
// @lc code=end
int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout<<s.maxSubArray(v)<<endl;
    return 0;
}
