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
    bool isEqual(TreeNode*a , TreeNode*b)
    {   if( a == NULL && b== NULL)return true;

        if( (a!= NULL && b==NULL) || (a==NULL && b!=NULL) )return false;
        bool l,r;
        if( a->val != b->val)
        {
            return false;
        }else{
           l =isEqual(a->left , b->right);
           r =isEqual(a->right , b->left);
        }

        return ( l && r);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        return isEqual(root->left , root->right);
    }
};