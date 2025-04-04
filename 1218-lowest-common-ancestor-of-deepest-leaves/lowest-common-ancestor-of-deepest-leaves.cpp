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


    unordered_map<int,int>umap;
    int maxDepth  = INT_MIN;
    void depth(int d,TreeNode* root)
    {
        if(!root)return ;

        maxDepth = max(maxDepth , d);
        umap[root->val] = d;

        depth(d+1,root->left);
        depth(d+1,root->right);

    }
    TreeNode* LCA(TreeNode* root)
    {
        if(root == NULL || umap[root->val] == maxDepth)
        {
            return root;
        }

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if( l != NULL && r!=NULL)return root;
        else if(l == NULL && r != NULL)return r;
        else if( l != NULL && r== NULL)return l;

        return NULL;

    }


    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        depth(0,root);
        return LCA(root);
    }
};