/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void VectorRecover(TreeNode* root, vector<int>& ans) {

        if (root == nullptr)
            return;

        VectorRecover(root->left, ans);
        ans.push_back(root->val);
        VectorRecover(root->right, ans);
    }

    void correctTree(TreeNode* root, vector<int>& ans, int& indx) {

        if (root == nullptr)
            return;

        correctTree(root->left, ans, indx);

        root->val = ans[indx++];

        correctTree(root->right, ans, indx);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        VectorRecover(root, ans);
        sort(ans.begin(), ans.end());
        int indx = 0;
        correctTree(root, ans, indx);
    }
};