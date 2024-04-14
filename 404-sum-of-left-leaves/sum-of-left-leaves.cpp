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

    int sum(TreeNode* root,TreeNode* parent)
    {
        if(root==NULL)
        {
            return 0;
        }

        if(root->left==NULL && root->right==NULL)
        {
            if(parent!=NULL)
            {
                if(parent->left==root)
                {
                    return root->val;
                }
            }
        }
        
        int ans = sum(root->left,root);
         ans +=sum(root->right,root);

        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res=sum(root,NULL);
        return res;
    }
};