/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int i = 0;
        for(int j=1; j<nums.size(); ++j){
            if(nums[i] != nums[j])
                nums[++i] = nums[j];
        }
        nums.resize(i+1);
        return i+1;
    }
};
// @lc code=end
int main()
{
    vector<int> v = {1,1,2,2,3};
    Solution s;
    cout<<s.removeDuplicates(v)<<endl;
    for(auto num: v)
        cout<<num<<" ";
    return 0;
}
