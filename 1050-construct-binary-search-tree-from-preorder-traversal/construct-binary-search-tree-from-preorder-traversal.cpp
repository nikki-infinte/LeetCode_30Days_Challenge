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

    TreeNode* bst(vector<int>pre ,  int& indx ,int low ,int high)
    {
        
        if(indx >= pre.size() )return nullptr;
        int val = pre[indx];
        if(val < low || val > high)return nullptr;
         indx+=1;
        TreeNode* root = new TreeNode(val);
        root->left = bst(pre,indx,low,root->val);
        root->right = bst(pre,indx,root->val,high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int indx =0;
        return bst(preorder,indx,INT_MIN,INT_MAX);
    }
};