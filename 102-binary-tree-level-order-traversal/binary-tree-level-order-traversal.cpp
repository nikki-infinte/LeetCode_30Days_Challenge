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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>>ans;
         if(root==NULL)
         {
            return ans;
         }

         queue<TreeNode*>q;
         q.push(root);
         vector<int>rem;
         rem.push_back(root->val);
         ans.push_back(rem);
        TreeNode* level;
         while(!q.empty())
         {

            int currsize=q.size();
            vector<int>tmp;
            while(currsize--)
            {
                level=q.front();
               
                q.pop();

                if(level->left)
                {
                    q.push(level->left);
                    tmp.push_back(level->left->val);
                }

                if(level->right)
                {
                    q.push(level->right);
                    tmp.push_back(level->right->val);
                }

            }

           
           if (!tmp.empty()) { // Only add non-empty levels
                ans.push_back(tmp);
            }
         }
    return ans;
        
    }
};