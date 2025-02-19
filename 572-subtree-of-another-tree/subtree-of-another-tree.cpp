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
    bool isIdentical(TreeNode* root ,TreeNode* subroot)
    {
        if(root == NULL && subroot == NULL)return true;
        else if( root == NULL || subroot == NULL ||root->val !=subroot->val)return false;


        if(! isIdentical(root->left , subroot->left))return false;
        if( ! isIdentical(root->right , subroot->right )) return false;


        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(root == NULL)return false;
        //dfs preorder
        if(root->val == subRoot->val)
        {
           if(isIdentical(root,subRoot))return true;

        }
       bool l =isSubtree(root->left , subRoot);
       bool r =isSubtree(root->right , subRoot);
       return l || r;

    }
};