/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preOrder(vector<int>&ans,Node* root){
        if(root == nullptr)return;

        ans.push_back(root->val);
        for(auto r:root->children){
            preOrder(ans,r);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        else preOrder(ans,root);
        return ans;
    }
};