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
    void inorder(TreeNode* root, vector<int>&oder) {

        if (!root)
            return;
        inorder(root->left, oder);
        oder.push_back(root->val);
         inorder(root->right, oder);
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int> oder;
        inorder(root, oder);
        int left = 0, right = oder.size() - 1;
        if(oder.size() == 1) return false;
        while (left < right) {
            if (oder[left] + oder[right] == k) {
                return true;
            } else if (oder[left] + oder[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};