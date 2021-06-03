/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> a;
    int idx;
public:
    Solution():a(20000*31, vector<int>(2,0)), idx(0) {}
    void insert(int x){
        int p = 0;
        for(int i=31; i>=0; --i){
            int u = p>>i&1;
            if(!a[p][u])
                a[p][u] = ++idx;
            p = a[p][u];
        }
    }
    int query(int x){
        int p = 0, res = 0;
        for(int i=31; i>=0; --i){
            int u = p>>i&1;
            if(a[p][u^1]){
                res = 2*res + u^1;
                p = a[p][u^1];
            }
            else{
                res = 2*res + u;
                p = a[p][u];
            }
        }
        return res^x;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(auto n: nums)
            insert(n);
        int res = 0;
        for(auto n: nums)
            res = max(res, query(n));
        return res;
    }
};
// @lc code=end
int main(){
    vector<int> a = {3,10,5,25,2,8};
    Solution s;
    cout<<s.findMaximumXOR(a)<<endl;
    return 0;
}
