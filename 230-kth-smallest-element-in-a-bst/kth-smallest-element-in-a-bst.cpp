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

    void inorder(vector<int>&inp,TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }

        inorder(inp,root->left);
        inp.push_back(root->val);
        inorder(inp,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inp;
        inorder(inp,root);

        return inp[k-1];
    }
};