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
    string res=" ";
    bool is_leaf(TreeNode* root)
    {
        if(root->left==NULL && root->right ==NULL)
        {
            return true;
        }
        else{
            return false;

        }
    }
    void Dfs_smallest(TreeNode* root,string cur)
    {

        if(root==NULL)
        {
            return ;
        }

        cur=char(root->val +'a')+cur;

        if(is_leaf(root))
        {
            if(res==" "|| res >cur)
            {
                res=cur;
            }
            return ;
        }
        Dfs_smallest(root->left,cur);
        Dfs_smallest(root->right,cur);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
         Dfs_smallest(root,"");
         return res;
    }
};