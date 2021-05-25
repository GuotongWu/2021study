/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp
        int min = prices[0];
        int maxPrices = 0;
        for(int i=1; i<prices.size(); ++i){
            if(prices[i] < min)
                min = prices[i];
            if(prices[i]-min > maxPrices)
                maxPrices = prices[i] - min;
        }
        return maxPrices;
    }
};
// @lc code=end
int main()
{
    vector<int> v = {7,6,4,3,1};
    Solution s;
    cout<<s.maxProfit(v)<<endl;
    return 0;
}
