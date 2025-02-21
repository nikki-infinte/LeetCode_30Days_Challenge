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
class FindElements {
public:

unordered_map<int,int>umap;

    void recover(TreeNode* root,int x)
    {
         if(root == NULL)return;

        
        root->val = x;
        umap[x]++;
        recover(root->left,2*x+1);
        recover(root->right,2*x+2);
    }
    FindElements(TreeNode* root) {

         if (root != NULL) {
            int x=0;
            recover(root, x);  // Start with root value as 0
        }
    }
   
    bool find(int target) {
        
        return (umap.find(target) !=umap.end());
      
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */