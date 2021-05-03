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
        bool flag_1=false,flag_2=false;
        int carry = 0;
        int add;
        int temp_1;
        ListNode *temp = new ListNode(0);
        ListNode *ans = temp;
        do{
            add=0;
            if(!flag_1){
                add += l1->val;
                l1 = l1->next;
                if(l1==NULL)
                    flag_1 = true;
            }
            if(!flag_2){
                add += l2->val;
                l2 = l2->next;
                if(l2==NULL)
                    flag_2 = true;
            }
            temp_1 = add;
            add = (carry+temp_1)%10;
            carry = (carry+temp_1)/10;
            temp->val = add;
            if(!flag_1 || !flag_2 || carry!=0){
                temp->next = new ListNode(0);
                temp = temp->next;
            }
        }while(!flag_1 || !flag_2 || carry!=0);
        return ans;
    }
        
};
