/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode *> m_stack;
    vector<int> m_ans;
    vector<int> inorderTraversal(TreeNode* root) {
        m_ans.clear();
        TreeNode *current = root;
        while(true){
            while(current){
                m_stack.push(current);
                current = current->left;
            }
            if(m_stack.empty()){
                return m_ans;
            }
            current = m_stack.top();
            m_stack.pop();
            
            m_ans.push_back(current->val);
            current = current->right;
        }
        return m_ans;
    }
};