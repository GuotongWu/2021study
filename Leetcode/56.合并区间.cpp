/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void quicksort(vector<vector<int>>& a, int left, int right){
        if(left>=right)
            return;
        int i=left-1, j=right+1, mid=a[left+right>>1][0];
        while(i<j){
            do ++i; while(a[i][0]<mid);
            do --j; while(a[j][0]>mid);
            if(i<j)
                swap(a[i],a[j]);
        }
        quicksort(a, left, j);
        quicksort(a, j+1, right);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        quicksort(intervals, 0, intervals.size()-1);
        vector<vector<int>> res;
        vector<int> val(2,0);
        for(int i=0,j=0; i<intervals.size(); ){
            val[0] = intervals[i][0];
            val[1] = intervals[i][1];
            while(j < intervals.size() && intervals[j][0] <= val[1]){
                val[1] = max(intervals[j][1], val[1]);
                ++j;
            }
            i = j;
            res.push_back(val);
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<vector<int> > intervals(2, vector<int>(2,0));
    intervals[0][0]=1; intervals[0][1]=4;
    intervals[1][0]=1; intervals[1][1]=4;
    // intervals[2][0]=8; intervals[2][1]=10;
    // intervals[3][0]=15; intervals[3][1]=18;
    s.quicksort(intervals, 0, intervals.size()-1);
    for(int i=0; i<intervals.size(); ++i)
        cout<<"["<<intervals[i][0]<<", "<<intervals[i][1]<<"], ";
    vector<vector<int>> res = s.merge(intervals);
    for(int i=0; i<res.size(); ++i)
        cout<<"["<<res[i][0]<<", "<<res[i][1]<<"], ";
    
    return 0;
}
