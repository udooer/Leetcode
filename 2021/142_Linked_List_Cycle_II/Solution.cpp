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
        std::unordered_map<ListNode*, int> hash_table;
        int pos = -1;
        while(head){
            if(hash_table.find(head) != hash_table.end())
                return head;
            else{
                pos += 1;
                hash_table[head] = pos;
                head = head->next;
            }
        }
        return NULL;
    }
};