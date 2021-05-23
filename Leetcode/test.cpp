/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(390);
        for(int day: days)
            memo[day]++;
        vector<int> dp(400);
        for(int i=366; i>=1; --i){
            int sum=0, sum7=0, sum30=0;
            if(memo[i])
                sum = dp[i+1] + costs[0];
            else 
                sum = dp[i+1];
            sum7 = dp[i+7] + costs[1];
            sum30 = dp[i+30] + costs[2];
            dp[i] = min(sum, min(sum7, sum30));
        }
        return dp[1];   
    }
};
// @lc code=end
int main()
{
    // Solution s;
    // vector<int> costs = {2,7,15};
    // vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    // cout<<s.mincostTickets(days, costs)<<endl;
    cout<<abs(-13/10)<<endl;
    return 0;
}