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
    
    void TargetFind(TreeNode* root, int sum , vector<int>path , vector<vector<int>>&paths) {
        if (root == nullptr) return ; 

      //include 
        sum-=root->val;
        path.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr)    {
            if( sum == 0) {
                paths.push_back(path);

            }
        }else{
        TargetFind(root->left ,sum,path,paths);
        TargetFind(root->right,sum,path,paths);
        }
        //exclude
        
        path.pop_back();
        
     
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>paths;
        TargetFind(root,targetSum,path,paths);
        return paths;
    }
};