/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针法
        if(head==nullptr)
            return false;
        ListNode * fast = head;
        ListNode * low = head;
        do{
            // 快指针每次向前2
            fast = fast->next;
            if(fast==nullptr) return false;
            fast = fast->next;
            if(fast==nullptr) return false;
            // 慢指针每次向前1
            low = low->next;
        }while(fast != low);
        // 可以证明，当fast=low时，迭代的次数刚好等于环的长度
        return true;
    }
};
// @lc code=end

