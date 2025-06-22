class Solution {
public:
    bool Valid(TreeNode* root , long long l , long long r)
    {
        if(root == nullptr) return true;

        if(root->val > l && root->val < r){
            return Valid(root->left, l, root->val) &&
                   Valid(root->right, root->val, r);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return Valid(root, LLONG_MIN, LLONG_MAX);
    }
};
