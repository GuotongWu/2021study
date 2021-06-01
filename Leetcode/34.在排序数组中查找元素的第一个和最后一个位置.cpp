/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> res(2,0);
        if (!nums.size()){
            res[0] = res[1] = -1;
            return res;
        } 
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l+r>>1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) res[0] = -1;
        else res[0] = l;
        l = 0, r = nums.size()-1;
        while(l<r){
            int mid = l+r+1>>1;
            if (nums[mid] <= target) l = mid;
            else r =  mid - 1;
        }
        if (nums[l] != target) res[1] = -1;
        else res[1] = l;
        return res;
    }
};
// @lc code=end
int main()
{
    return 0;
}
