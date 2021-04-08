/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口+哈希表
        int maxLen = 0;
        int right = 0;
        unordered_map<char, int> hashtable;
        for(int i=0; i<s.length() && right<s.length(); ++i){
            while(1){
                auto posi = hashtable.find(s[right]);
                if(posi==hashtable.end() && right<s.length()){ // 哈希表中找到，右指针右移
                    hashtable[s[right++]] = 1;
                }
                else{ // 反之找到，将左指针删去
                    hashtable.erase(s[i]);
                    break;
                }
            }
            if(maxLen<right-i)
                maxLen = right-i;
        }
        return maxLen;
    }
};
// @lc code=end
int main()
{
    string str = "bbbbbb";
    Solution s;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}
