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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int,TreeNode*>nodes;
        unordered_set<int>children;
        for(const auto& desc:descriptions)
        {
            int parentval=desc[0];
            int childval=desc[1];
            bool isLeft=desc[2]==1;


            if(nodes.find(parentval) == nodes.end())
            {
                nodes[parentval]=new TreeNode(parentval);
            }
            if(nodes.find(childval) == nodes.end())
            {
                nodes[childval]=new TreeNode(childval);
            }
            if(isLeft)
            {
                nodes[parentval]->left=nodes[childval];
            }else{
                nodes[parentval]->right=nodes[childval];
            }
            children.insert(childval);
        }
     
    
 TreeNode* root=nullptr;

    for(auto &[val,n]:nodes)
    {
       if(children.find(val)==children.end())
        {
            root=n;
            break;
        }

    }
    return root;
    }
};