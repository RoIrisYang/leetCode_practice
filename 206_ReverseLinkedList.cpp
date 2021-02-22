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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode* cur = head->next;
        ListNode* next = cur->next;
        ListNode* pre = head;
        pre->next = NULL;
        
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;            
        }
        
        return pre;
    }
};

/* cool recursive solution */
/*
ListNode* reverseList(ListNode* head) {
    if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}
*/