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
        int number = lists.size();
        if(number==0)
            return NULL;
        else{
            int i=0;
            while(i<lists.size()){
                if(lists[i]==NULL){
                    lists.erase(lists.begin()+i);
                    number--;
                }
                else
                    i++;
            }
            if(number==0)
                return NULL;
        }
        ListNode *ans=new ListNode;
        ListNode *temp=ans;
        ListNode *temp1;
        while(number){
            int min=1000000000;
            int index=-1;
            for(int i=0;i<number;i++){
                if(lists[i]->val<min){
                    index=i;
                    min=lists[i]->val;
                }
            }
            temp->val = min;
            temp->next = new ListNode;
            temp1 = temp;
            temp = temp->next;
            if(lists[index]->next){
                lists[index]=lists[index]->next;
            }
            else{
                lists.erase(lists.begin()+index);
            }
            number = lists.size();
        }
        temp1->next=NULL;
        return ans;
    }
};
