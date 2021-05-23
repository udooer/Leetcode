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
        priority_queue<ListNode*, vector<ListNode*>, compareVal> Q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                Q.push(lists[i]);
            }
        }
        if(Q.empty())
            return NULL;
        ListNode* head = new ListNode();
        ListNode* ans = head;
        ListNode* pre;
        while(!Q.empty()){
            ListNode* l = Q.top();
            Q.pop();
            if(l->next)
                Q.push(l->next);
            head->val = l->val;
            head->next = new ListNode();
            pre = head;
            head = head->next;
        }
        pre->next = NULL;
        delete head;
        return ans;
    }
private:
    struct compareVal{
        bool operator()(ListNode* & l1, ListNode* & l2){
            return (l1->val) > (l2->val);
        }
    };
};