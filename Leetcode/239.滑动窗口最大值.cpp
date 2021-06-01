/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qe;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            if(!qe.empty() && qe.front()<i-k+1)
                qe.pop_front();
            while(!qe.empty() && nums[qe.back()]<=nums[i])
                qe.pop_back();
            qe.push_back(i);
            if(i-k+1 >= 0)
                res.push_back(nums[qe.front()]);
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = s.maxSlidingWindow(nums, 3);
    for(int i=0; i<res.size(); ++i)
        cout<<res[i]<<" ";
    return 0;
}
