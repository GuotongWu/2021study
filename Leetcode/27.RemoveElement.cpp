/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j=0; j<nums.size(); ++j){
            if(nums[j] != val)
                nums[i++] = nums[j];
        }
        nums.resize(i);
        return i;
    }
};
// @lc code=end
int main()
{
    vector<int> v = {1,1,2,2,3};
    Solution s;
    cout<<s.removeElement(v, 0)<<endl;
    for(auto num: v)
        cout<<num<<" ";
    return 0;
}
