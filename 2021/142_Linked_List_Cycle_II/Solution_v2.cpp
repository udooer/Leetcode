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
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode*> hash_set;
        while(head){
            if(hash_set.find(head) != hash_set.end())
                return head;
            else{
                hash_set.insert(head);
                head = head->next;
            }
        }
        return NULL;
    }
};