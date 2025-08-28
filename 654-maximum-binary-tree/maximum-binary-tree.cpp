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
int MaximumIndexVal(vector<int>array,int i,int j){
    int maxElm = array[i] , maxIndx =i;
    for(int k = i;k<=j;k++){
        if(maxElm < array[k]){
            maxElm = array[k];
            maxIndx = k;
        }
    }
    return maxIndx;
}

    TreeNode* solve(int low ,int high,vector<int>&nums){

       if (low > high) return nullptr;



        int indx = MaximumIndexVal(nums,low,high);
        TreeNode* node = new TreeNode(nums[indx]);

        node->left = solve(low,indx-1,nums);
        node->right = solve(indx+1,high,nums);
        return node;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return  solve(0,nums.size()-1,nums);
    }
};