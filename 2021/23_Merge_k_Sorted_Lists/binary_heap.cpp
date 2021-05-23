#include<iostream>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct CompareVal {
    bool operator()(ListNode* & l1, ListNode* & l2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return (l1->val) > (l2->val);
    }
};
int main(){
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(-6);
    ListNode* c = new ListNode(-3);
    ListNode* d = new ListNode(100);
    ListNode* e = new ListNode(31);

    priority_queue<ListNode*, vector<ListNode*>, CompareVal> Q;

    Q.push(a);
    Q.push(b);
    Q.push(c);
    Q.push(d);
    Q.push(e);

    while (!Q.empty()) {
        ListNode* l = Q.top();
        Q.pop();
        cout << l->val << "\n";
    }

    return 0;
}