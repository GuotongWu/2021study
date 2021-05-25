/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 使用先删除，再在尾部添加的方法
        int i=0,j=0;
        for(; j<nums.size(); ++j)
            if(nums[j])
                nums[i++] = nums[j];
        for(; i<nums.size(); ++i)
            nums[i] = 0;
    }
};
// @lc code=end
int main()
{

    vector<int> v = {0,1,0,3,12};
    Solution s;
    s.moveZeroes(v);
    for(auto num: v)
        cout<<num<<" ";
    return 0;
}