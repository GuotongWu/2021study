/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * preHead = new ListNode(-1); // 采用哨兵结点的方式
        ListNode * pre = preHead;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val <= l2->val){
                pre->next = l1;
                pre = pre->next;
                l1 = l1->next;
            }else{
                pre->next = l2;
                pre = pre->next;
                l2 = l2->next;
            }
        }
        if(l1==nullptr)
            pre->next = l2;
        else
            pre->next = l1;
        return preHead->next;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> v1 = {2};
    vector<int> v2 = {1};
    ListNode * head1 = new ListNode();
    ListNode * tp_head1 = head1;
    ListNode * head2 = new ListNode();
    ListNode * tp_head2 = head2;
    for(int i=0; i<v1.size(); ++i){
        tp_head1->next = new ListNode(v1[i]);
        tp_head1 = tp_head1->next;
    }
    for(int i=0; i<v2.size(); ++i){
        tp_head2->next = new ListNode(v2[i]);
        tp_head2 = tp_head2->next;
    }
    tp_head1 = s.mergeTwoLists(head1->next, head2->next);
    while(tp_head1){
        cout<<tp_head1->val<<"->";
        tp_head1 = tp_head1->next; 
    }
    cout<<"NULL"<<endl;
    return 0;
}