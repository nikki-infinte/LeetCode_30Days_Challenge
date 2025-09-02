class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> mp;
        vector<int> vec;
        
        st.push(root);
        mp[root] = 0;
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            mp[node]++;
            
            if (mp[node] == 2) {
                vec.push_back(node->val);
            } else {
                st.push(node); // push back for second visit
                
                if (node->right) st.push(node->right); // push right first
                if (node->left) st.push(node->left);   // then left
            }
        }
        
        return vec;
    }
};
