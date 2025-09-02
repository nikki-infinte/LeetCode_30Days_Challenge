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
    int balance(TreeNode* root){
        
        if(root == nullptr)return 0;


        int leftBal = balance(root->left);
        if(leftBal == -1)return -1;
        int rightBal = balance(root->right);
        if(rightBal == -1)return -1;

        if (abs(leftBal-rightBal) > 1 ){
            return -1;
        }

        return max(leftBal,rightBal)+1;
    }
    bool isBalanced(TreeNode* root) {
        return balance(root)!=-1;
    }
};