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

class BSTIterator{
    stack<TreeNode*>stk;
    bool forward;
    public:
        BSTIterator(TreeNode* root,bool isForward):forward(isForward){
            pushAll(root);
        }


        int next(){
            TreeNode* node = stk.top();
            stk.pop();

            if(forward)pushAll(node->right);
            else pushAll(node->left);

            return node->val;
        }


    bool hasNext() {
        return !stk.empty();
    }
    private:
    void pushAll(TreeNode* root){
        while(root){
            stk.push(root);
            root = forward ? root->left : root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;

         BSTIterator l(root, true);   // in-order
        BSTIterator r(root, false); // reverse in-order

        int i = l.next(), j = r.next();
        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};