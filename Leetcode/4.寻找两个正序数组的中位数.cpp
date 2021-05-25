/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int i=0, j=0, k=0;
        int first = 0, next = 0;
        for(; k!=len/2+1 && i<nums1.size() && j<nums2.size(); ++k){
            first = next;
            nums1[i] <= nums2[j]? next=nums1[i++]: next=nums2[j++];
        }
        if(i == nums1.size())
            for(; j<nums2.size() && k!=len/2+1; ++k){
                first = next;
                next = nums2[j++];
            }
        else if(j == nums2.size())
            for(; i<nums1.size() && k!=len/2+1; ++k){
                first = next;
                next = nums1[i++];
            }
        return len%2? next: (next+first)/2.0;
    }
};
// @lc code=end
int main()
{
    vector<int> v1 = {0,0};
    vector<int> v2 = {2,4};
    Solution s;
    cout<<s.findMedianSortedArrays(v1, v2)<<endl;
    return 0;
}
