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

    void Traversal(TreeNode* root,vector<int>&pre)
    {
        if(root == NULL)return ;

        pre.push_back(root->val);
        Traversal(root->left,pre);
        Traversal(root->right,pre);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        Traversal(root,pre);
        return pre;
    }
};