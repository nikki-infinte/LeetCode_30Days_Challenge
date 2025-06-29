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

 bool TargetFind(TreeNode* root, int sum) {
    if (root == nullptr) return false;   
    sum -= root->val;
    if (root->left == nullptr && root->right == nullptr) {
        return sum == 0;
    }
    return TargetFind(root->left, sum) || TargetFind(root->right, sum);
}

    bool hasPathSum(TreeNode* root, int targetSum) {
        return TargetFind(root,targetSum);
    }
};