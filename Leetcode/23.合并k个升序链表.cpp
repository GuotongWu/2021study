/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct status{
    ListNode * node;
    bool operator < (const status & s) const{
        return  node->val > s.node->val; 
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return nullptr;
        priority_queue<status> q;
        for(auto item: lists)
            if(item)
                q.push({item}); 
        if(q.empty())
            return nullptr; 
        ListNode * head = new ListNode(q.top().node->val);
        ListNode * tail = head;
        if(q.top().node->next)
            q.push({q.top().node->next});
        q.pop();
        while(!q.empty()){
            tail->next = new ListNode(q.top().node->val);
            tail = tail->next;
            if(q.top().node->next)
                q.push({q.top().node->next});
            q.pop();
        }
        return head;
    }
};
// @lc code=end

