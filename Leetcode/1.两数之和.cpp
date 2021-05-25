/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i=0; i<nums.size(); ++i){
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()){ // 找到了
                return {it->second, i};
            }else{
                hashtable[nums[i]] = i;
            }
        }
        return {};
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> num = {2, 3, 5, 11};
    vector<int> result = s.twoSum(num, 9);
    for(auto num: result)
        cout<<num<<" ";
    return 0;
}
