/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 位运算
        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();
        for(int m=0; m<(1<<n); ++m){ // eg: n=5 => m<100000=11111+1
            temp.clear();
            for(int i=0; i<nums.size(); ++i){
                if(m & (1<<i))     // 满足条件的数
                    temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end
void print_vec(vector<int> v){
    cout<<"[";
    for(int i=0; i<v.size(); ++i)
        cout<<v[i]<<",";
    cout<<"]";
}

int main()
{
    vector<int> v = {0};
    Solution s;
    vector<vector<int>> ans = s.subsets(v);
    for(int i=0; i<ans.size(); ++i){
        print_vec(ans[i]);
        cout<<",";
    }
    cout<<endl;
    return 0;
}

