/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1, l2;
        ListNode *tailA=headA, *tailB=headB;
        for(l1=0; tailA->next!=nullptr; ++l1)
            tailA = tailA->next;
        for(l2=0; tailB->next!=nullptr; ++l2)
            tailB = tailB->next;
        if(l1 > l2)
            for(int i=0; i<l1-l2; ++i)
                headA = headA->next;
        else if(l2 > l1)
            for(int i=0; i<l2-l1; ++i)
                headB = headB->next;
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
// @lc code=end

