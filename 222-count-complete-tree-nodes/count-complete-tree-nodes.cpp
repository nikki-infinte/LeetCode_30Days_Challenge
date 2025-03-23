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

    int left_height(TreeNode* root)
    {
        int ht = 0;
        while(root!=NULL)
        {
            ht++;
            root = root->left;
        }
        return ht;
    }
    int right_height(TreeNode* root)
    {
        int ht = 0;
        while(root)
        {
            ht++;
            root=root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;

        int l = left_height(root);
        int r = right_height(root);

        if(l == r)
        {
            return (pow(2,l)-1);
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};