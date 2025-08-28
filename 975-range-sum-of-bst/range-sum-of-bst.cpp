class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        // If current node is less than low, skip left subtree
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        // If current node is greater than high, skip right subtree
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        // Current node is within range, include its value and recurse both sides
        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};
