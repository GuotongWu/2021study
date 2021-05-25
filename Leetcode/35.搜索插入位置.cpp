/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size(), m;
        while(i < j){
            m = (i+j) >> 1;
            if(nums[m] < target)
                i = m + 1;
            else 
                j = m;
        }
        return i;
    }
};
// @lc code=end
int main()
{
    vector<int> v = {1,3,5,6};
    Solution s;
    cout<<s.searchInsert(v, 4)<<endl;
    for(auto num: v)
        cout<<num<<" ";
    return 0;
}
