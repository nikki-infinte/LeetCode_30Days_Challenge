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
    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return ans;
        }

        unordered_map<TreeNode*, int> mp;
        mp[root] = 0;

        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);

        while(!st.empty()){

            TreeNode* elem =st.top();
            st.pop();

            mp[elem]++;
            if(mp[elem] == 2){
                ans.push_back(elem->val);
            }else{
                if(elem->right)st.push(elem->right);
                st.push(elem);
                if(elem->left)st.push(elem->left);
            }
        }
        return ans;
    }
};