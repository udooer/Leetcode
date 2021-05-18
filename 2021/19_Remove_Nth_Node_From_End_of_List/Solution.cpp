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
        std::vector<ListNode*> vector_of_listNode_pointer;
        ListNode* ans = head;
        while(head!=NULL){
            vector_of_listNode_pointer.push_back(head);
            head = head->next;
        }
        if(vector_of_listNode_pointer.size()-n==0){
            cout<<"Inside";
            return ans->next;
        }
        if(n==1){
            vector_of_listNode_pointer[vector_of_listNode_pointer.size()-1-n]->next = NULL;
            return ans;
        }
        vector_of_listNode_pointer[vector_of_listNode_pointer.size()-1-n]->next = vector_of_listNode_pointer[vector_of_listNode_pointer.size()-1+2];
        return ans;
    }
};