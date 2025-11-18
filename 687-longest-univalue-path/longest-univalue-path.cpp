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
    int maxVal = 0;
    int DFS(TreeNode* root){

        if(!root)return 0 ;
       int left =  DFS(root->left);
       int right = DFS(root->right);

        int leftPath =0,rightPath =0;
        if(root->left && root->left->val == root->val){
            leftPath=left + 1;
        }
        if(root->right && root->right->val == root->val){
            rightPath= right +1;
        }
     maxVal = max(maxVal, leftPath + rightPath);

    return max(leftPath, rightPath);

    }
    int longestUnivaluePath(TreeNode* root) {
        DFS(root);
        return maxVal;
       
    }
};