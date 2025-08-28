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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*>st;

        for(auto n:nums){
            TreeNode* node = new TreeNode(n);
            while(!st.empty() && st.top()->val < n  ){
                node->left = st.top();
                st.pop();
            }


            if(!st.empty())
            {
                st.top()->right = node;
            }

            st.push(node);
        }
         // Root is at bottom of stack
        while (st.size() > 1) st.pop();
        return st.top();
    }
};