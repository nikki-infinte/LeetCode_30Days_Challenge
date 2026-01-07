class Solution {
public:
    long long TotalSum = 0;
    long long maxPr = 0;
    const int MOD = 1e9+7;

    long long totalSum(TreeNode* root) {
        if(root == nullptr) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long find(TreeNode* root) {
        if(root == nullptr) return 0;

        long long lsum = find(root->left);
        long long rsum = find(root->right);

        long long subSum = lsum + rsum + root->val;
        long long remSum = TotalSum - subSum;

        maxPr = max(maxPr, subSum * remSum);
        return subSum;
    }

    int maxProduct(TreeNode* root) {
        TotalSum = totalSum(root);
        maxPr = 0;
        find(root);
        return maxPr % MOD;
    }
};
