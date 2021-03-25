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
        int tempLen = 0; 
        int left, right;
        unordered_map<char, int> hashtable;
        for(int i=0; i<s.length(); ++i){
            left = i;
            right = left + 1;
            hashtable[s[left]] = 1;
            while(1){
                auto posi = hashtable.find(s[right]);
                if(posi != hashtable.end()){
                    ++right;
                    ++tempLen;
                }
                else{
                    hashtable.erase()
                    break;
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end
int main()
{
    return 0;
}
