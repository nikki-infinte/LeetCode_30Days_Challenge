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

    TreeNode* solve(int& indx,int ub,vector<int>& preorder){

        if(indx == preorder.size() || preorder[indx] >ub){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[indx++]);
        root->left = solve(indx,root->val,preorder);
        root->right = solve(indx,ub,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int indx =0;
     return solve(indx,INT_MAX,preorder);   
    }
};