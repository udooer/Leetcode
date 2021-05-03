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
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1 && !l2)
            return NULL;
        else if(l1 && !l2)
            return l1;
        else if(!l1 && l2)
            return l2;
        ListNode* ans = new ListNode();
        ListNode* first = ans;
        while(1){
            if(l1->val <= l2->val){
                ans->val = l1->val;
                l1 = l1->next;
                if(l1){
                    ans->next = new ListNode();
                    ans = ans->next;
                }
                else{
                    ans->next = l2;
                    break;
                }
            }
            else{
                ans->val = l2->val;
                l2 = l2->next;
                if(l2){
                    ans->next = new ListNode();
                    ans = ans->next;
                }
                else{
                    ans->next = l1;
                    break;
                }
            }
        }
        return first;
    }
};