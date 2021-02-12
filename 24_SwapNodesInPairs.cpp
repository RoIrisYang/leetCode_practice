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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        
        ListNode* previous = NULL;
        ListNode* first = head;
        ListNode* second = head->next;
        while(first && second){
            cout << first->val << " " << second->val << endl;
            
            /* swap two */
            if (previous) previous->next = second;
            else head = second;  // for the first
            first->next = second->next;
            second->next = first;
            
            cout << second->val << " " << second->next->val << endl <<endl;
            
            /* to next pair if exist */
            previous = first;
            first = previous->next;
            if(first) second = first->next;
        }
        
        return head;
    }
};