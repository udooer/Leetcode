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
    vector<int> m_ans;
    vector<int> inorderTraversal(TreeNode* root) {
        m_ans.clear();
        helper(root);
        return m_ans;
    }
    void helper(TreeNode *current){
        if(current){
            helper(current->left);
            m_ans.push_back(current->val);
            helper(current->right);
        }
    }
};