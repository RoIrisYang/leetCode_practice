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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {  
        // point to head first
        ListNode* cur_l1 = l1;
        ListNode* cur_l2 = l2;
        ListNode* ans = NULL;
        ListNode* curAns;
        
        bool carry = false;
        int sum;
        while(cur_l1 != NULL || cur_l2 != NULL){  
            sum = 0;       
            if(carry) sum = 1;
            
            carry = false;            
            
            if (cur_l1 != NULL)
            {
                sum += cur_l1->val;
                cout << cur_l1->val;
            }
            
            cout << " + ";
            
            if (cur_l2 != NULL)
            {
                sum += cur_l2->val;  
                cout << cur_l2->val;
            }
            
            if(sum > 9){
                carry = true;
                sum -= 10;
            }
            cout << " = " << sum << " " << carry <<endl;
                        
            if (cur_l1 != NULL){
                cur_l1 = cur_l1->next;                
            }
            
            if (cur_l2 != NULL){
                cur_l2 = cur_l2->next;
            }            
            
            cout << sum << endl;
            if(ans == NULL)
            {               
                ans = new ListNode(sum);
                curAns = ans;
            }                
            else
            {
                if(curAns == NULL) cout<<"isNULL";
                curAns->next = new ListNode(sum);
                curAns = curAns->next;
            }                          
        }
        
        if (carry) curAns->next = new ListNode(1);
            
        
        return ans;
    }
};

/* others' clean solution
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head= new ListNode(0);
    ListNode *l3=head;
    int carry = 0;
    while(l1 || l2|| carry){
        int l1_val = (l1!=NULL)?l1->val:0;
        int l2_val = (l2!=NULL)?l2->val:0;
        
        int current_sum = l1_val +l2_val + carry;
        carry = current_sum/10;
        int last_digit = current_sum%10;
        
        l3->next = new ListNode(last_digit);
        
        if(l1!=NULL) {l1=l1->next;}
        if(l2!=NULL) {l2=l2->next;}
        l3=l3->next;
    }
    
    return head->next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int sum = 0;
    while (l1 || l2 || sum) {
      sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
      tail->next = new ListNode(sum % 10);
      sum /= 10;
      tail = tail->next;
    }            
    return dummy.next;
}
*/