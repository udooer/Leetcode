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
    ListNode* mergeKLists(vector<ListNode*>& lists){
        std::list<ListNode*> linked_list;
        linked_list.assign(lists.begin(), lists.end());
        ListNode* head = new ListNode();
        ListNode* ans = head;
        int min;
        std::list<ListNode*>::iterator index, it;
        for(it=linked_list.begin();it!=linked_list.end();){
            if(!(*it))
                it = linked_list.erase(it);
            else
                it++;
        }
        int length = linked_list.size();
        if(length == 0)
            return NULL;
        while(linked_list.size()>1){
            min = 100000;
            for(it=linked_list.begin();it!=linked_list.end();it++){
                if((*it)->val<=min){
                    min = (*it)->val;
                    index = it;
                }
            }
            if((*index)->next)
                *index = (*index)->next;
            else
                linked_list.erase(index);
            
            head->next = new ListNode();
            head->val = min;
            head = head->next;
        }
        ListNode* only_one = linked_list.front();
        head->val = only_one->val;
        if(only_one->next)
            head->next = only_one->next;
        return ans;
    }
};  