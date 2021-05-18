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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first;
        ListNode* second;
        int count = 0;
        first = head;
        second = head;
        while(1){
            if(first->next)
                first = first->next;
            else 
                break;
            if(count>=n){
                second = second->next;
            }
            count+=1;
        }
        if(n == count+1)
            return head->next;
        if(n == 1){
            second->next = NULL;
            return head;
        }
        second->next = second->next->next;
        return head;
    }
};