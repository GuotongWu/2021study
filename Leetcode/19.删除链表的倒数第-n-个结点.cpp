/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> temp;
        ListNode * curr = head;
        while(curr){
            temp.push_back(curr);
            curr = curr->next;
        }
        int pos = temp.size()-n-1;
        if(pos == -1)
            return head=head->next;
        else{
            ListNode * remove = temp[pos];
            remove->next = remove->next->next;
            return head;
        }
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> v = {1,2,3,4,5};
    ListNode * head = new ListNode(v[0]);
    ListNode * tp_head = head;
    for(int i=1; i<v.size(); ++i){
        tp_head->next = new ListNode(v[i]);
        tp_head = tp_head->next;
    }
    tp_head = nullptr;
    tp_head = s.removeNthFromEnd(head, 1);
    while(tp_head){
        cout<<tp_head->val<<"->";
        tp_head = tp_head->next; 
    }
    cout<<"NULL"<<endl;
    return 0;
}