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
    int sum(TreeNode* root,int cur)
    {
         if(root==NULL)
        {
            return 0;
        }
       
        cur=cur*10+root->val;
        if(root->left==NULL && root->right ==NULL)
        {
            return cur;
        }

        int l=sum(root->left,cur);
        int r=sum(root->right,cur);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
     
        int ans= sum(root,0);
        return ans;
        
    }
};