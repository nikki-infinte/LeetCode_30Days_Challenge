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
    TreeNode* findMin(TreeNode* root)
    {
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
     
        //edge case 
        if(root == nullptr){
            return root;
        }

        if(root->val > key){
              root->left = deleteNode(root->left,key);
        }else if(root->val < key){
              root->right = deleteNode(root->right,key);
        }else{

            //node found
            //case 1 : node with one hild or no child

            if(root->left == nullptr){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }else if(root->right == nullptr){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }

            //case 2 : Node with 2 children 
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;

            root->right = deleteNode(root->right,temp->val );
            

        }
        return root;

        
       
    }
};