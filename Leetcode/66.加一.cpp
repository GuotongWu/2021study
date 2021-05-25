/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 0;
        digits[digits.size()-1]++;
        for(int i=digits.size()-1; i>=0; --i){
            digits[i] += flag;
            if(digits[i]==10){
                flag = 1;
                digits[i] = 0;
            }else
                flag = 0;
        }
        if(!digits[0])
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end
int main()
{
    vector<int> v = {9,9,8};
    Solution s;
    vector<int> ans = s.plusOne(v);
    for(auto num: ans)
        cout<<num<<" ";
    return 0;
}
