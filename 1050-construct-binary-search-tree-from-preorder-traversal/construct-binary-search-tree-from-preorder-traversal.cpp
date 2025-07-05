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

    TreeNode* create(TreeNode* root,int elem){
        if(root == nullptr){
            root = new TreeNode(elem);
            return root;
        }


        if(root->val < elem){
            root->right = create(root->right, elem);
        }else if(root->val > elem){
            root->left = create(root->left,elem);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
           root =create(root,preorder[i]);
        }
        return root;
    }
};