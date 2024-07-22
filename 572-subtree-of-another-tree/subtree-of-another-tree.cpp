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
  // Function to check if two trees are identical
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val) &&
               isSameTree(t1->left, t2->left) &&
               isSameTree(t1->right, t2->right);
    }

   bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        // Check if the current tree rooted at 'root' is identical to 'subRoot'
        if (isSameTree(root, subRoot)) return true;
        // Recur for left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
