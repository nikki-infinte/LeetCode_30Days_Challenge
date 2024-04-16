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
TreeNode* add(TreeNode* n,int depth,int cur,int val)
{
    if(n==NULL)
    {
        return NULL;

    }
    
    if(cur==depth-1){
        TreeNode* leftn=n->left;
        TreeNode* rightn=n->right;
        

        n->left=new TreeNode(val);
        n->right=new TreeNode(val);

        n->left->left=leftn;
        n->right->right=rightn;

        return n;
    }
    n->left=add(n->left,depth,cur+1,val);
    n->right=add(n->right,depth,cur+1,val);

    return n;
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int curr=1;
        if(depth==1)
        {
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }else{
        root=add(root,depth,curr,val);
        return root;
        }
    }
};