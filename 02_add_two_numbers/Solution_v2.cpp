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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        int add;
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        do{
            add=0;
            if(l1!=NULL){
                add += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                add += l2->val;
                l2 = l2->next;
            }
            if(carry)
                add++;
            carry = add>=10?true:false;
            temp->next = new ListNode(add%10);
            temp = temp->next;
        }while(l1!=NULL || l2!=NULL);
        if(carry)
            temp->next = new ListNode(1);
        return ans->next;
    }
        
};
