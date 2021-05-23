/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l+r+1>>1;
            if(nums[mid] <= target)
                l = mid;
            else
                r = mid-1;
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
};
// @lc code=end

bool check(int mid){return true;}

int bin_search1(int a[], int l, int r){
    while(l<r){
        int mid = l+r>>1;
        if (check(mid)) // 当最终的结果a[mid]全部在target左边
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

int bin_search2(int a[], int l, int r)
{
    while(l>r){
        int mid = l+r+1>>1; // 注意加1
        if (check(mid)) // 当最终的结果a[mid]全部在target的右边
            l = mid;
        else
            r = mid-1;
    }
    return l;
}
int main()
{
    Solution s;
    vector<int> a = {1,5};
    int target = 5;
    cout<<s.search(a, target)<<endl;
    return 0;
}