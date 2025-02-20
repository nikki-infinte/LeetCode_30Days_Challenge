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

   void postorder( TreeNode* root,int& min1 , long& min2)
   {
    if(root == NULL)
    {
        return ;
    }


    postorder(root->left,min1,min2);
    postorder(root->right,min1,min2);

    if(root->val > min1 && root->val < min2)
    {
        min2 = root->val;
    }
   }
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)return -1 ;
   
        long min2 = LONG_MAX;

        postorder(root,root->val ,min2);
          return (min2 == LONG_MAX) ? -1 : min2;
       
    }
};