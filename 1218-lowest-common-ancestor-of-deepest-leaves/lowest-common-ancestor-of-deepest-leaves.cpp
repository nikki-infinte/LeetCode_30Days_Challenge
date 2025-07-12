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

     map<int,vector<TreeNode*>>mp;
   int levelDepth(TreeNode* root){
        if(root==nullptr)return 0 ;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxd=0;
        
        while(!q.empty()){
            
                auto [node,d] = q.front();
                q.pop();

                
                maxd = max(d,maxd);

                mp[d].push_back(node);
                if(node->left){
                    q.push({node->left , d+1} );
                }
                if(node->right){
                    q.push({node->right,d+1});
                }
            
        }
    return maxd;
    }

    TreeNode* LCA(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root == nullptr || root == p || root == q)return root;
        TreeNode* lt = LCA(root->left,p,q);
        TreeNode* rt =LCA(root->right,p,q);

        if(lt == NULL)return rt;
        else if(rt == NULL)return lt;
        else return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        mp.clear();
        int maxd = levelDepth(root);
        vector<TreeNode*>deepest = mp[maxd];
        TreeNode* lca = deepest[0];
        for(int i=1;i<deepest.size();++i){
            lca = LCA(root,lca,deepest[i]);
        }
    return lca;

    }
};