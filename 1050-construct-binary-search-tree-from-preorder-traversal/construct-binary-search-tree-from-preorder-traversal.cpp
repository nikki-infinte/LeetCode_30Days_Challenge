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

    TreeNode* insert(int x,TreeNode* root){

        if(root == nullptr){
            TreeNode* newNode = new TreeNode(x);
            return newNode;
        }

        if(root->val < x){
            root->right = insert(x,root->right);
        }else{
            root->left = insert(x,root->left);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            root = insert(preorder[i],root);
        }
        return root;
    }
};