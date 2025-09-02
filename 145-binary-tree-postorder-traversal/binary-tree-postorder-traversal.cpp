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

   
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
      st.push(root);
        vector<int>ans;
      while(!st.empty()){

        TreeNode* vec = st.top();
        st.pop();

        if(vec)ans.push_back(vec->val);
         if(vec &&vec->left){
            st.push(vec->left);
        }
        if(vec && vec->right){
            st.push(vec->right);
        }
       
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};