/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> pre(mat.size()+1, vector<int>(mat[0].size()+1, 0));
        pre = prefix(mat);
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        int x1,x2,y1,y2;
        for(int i=0; i<mat.size(); ++i)
            for(int j=0; j<mat[0].size(); ++j){
                y1 = j-k>0?j-k:0;
                y2 = j+k<mat[0].size()?j+k:mat[0].size()-1;
                x1 = i-k>0?i-k:0;
                x2 = i+k<mat.size()?i+k:mat.size()-1;
                ans[i][j] = pre[x2+1][y2+1] - pre[x1][y2+1] - pre[x2+1][y1] + pre[x1][y1];
            }
        return ans;
    }
    vector<vector<int>> prefix(vector<vector<int>>& mat){
        vector<vector<int>> v(mat.size()+1, vector<int>(mat[0].size()+1, 0));
        for(int i=1; i<=mat.size(); ++i)
            for(int j=1; j<=mat[0].size(); ++j)
                v[i][j] = mat[i-1][j-1] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        return v;
    }
};
// @lc code=end
void print_vector(vector<vector<int>> mat){
    for(int i=0; i<mat.size(); ++i){
        for(int j=0; j<mat[0].size(); ++j)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}


int main()
{
    vector<vector<int>> mat(3, vector<int>(3,0));
    int k = 0;
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            mat[i][j] = ++k;
    Solution s;
    print_vector(mat);
    print_vector(s.prefix(mat));
    print_vector(s.matrixBlockSum(mat, 2));
    return 0;
}