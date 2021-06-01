/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for(int i=0,j=height.size()-1; i!=j;){
            res = max(res, (j-i)*min(height[i],height[j]));
            height[i]>=height[j]?--j:++i;
        }
        return res;
    }
};
// @lc code=end
int main(){
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout<<s.maxArea(v)<<endl;
    return 0;
}
