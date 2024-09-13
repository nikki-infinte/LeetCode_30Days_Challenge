class Solution {
public:
    struct TNode {
        TNode* left;
        TNode* right;
        TNode() : left(nullptr), right(nullptr) {}
    };

    void insert(TNode* root, int num) {
        TNode* pcrawl = root;

        for (int i = 31; i >= 0; i--) {
            int ith = (num >> i) & 1;
            if (ith == 0) {
                if (pcrawl->left == nullptr) {
                    pcrawl->left = new TNode();
                }
                pcrawl = pcrawl->left;
            } else {
                if (pcrawl->right == nullptr) {
                    pcrawl->right = new TNode();
                }
                pcrawl = pcrawl->right;
            }
        }
    }

    int findMax(TNode* root, int num) {
        int maxXor = 0;
        TNode* p = root;

        for (int i = 31; i >= 0; i--) {
            int ith = (num >> i) & 1;

            // We want to maximize the XOR, so we prefer opposite bit if available
            if (ith == 0) {
                if (p->right != nullptr) {
                    maxXor |= (1 << i); // Add 2^i to the result using bitwise shift
                    p = p->right;
                } else {
                    p = p->left;
                }
            } else {
                if (p->left != nullptr) {
                    maxXor |= (1 << i); // Add 2^i to the result using bitwise shift
                    p = p->left;
                } else {
                    p = p->right;
                }
            }
        }
        return maxXor; // Return the calculated maximum XOR for this number
    }

    int findMaximumXOR(vector<int>& nums) {
        TNode* root = new TNode();
        
        // Insert all numbers into the Trie
        for (int i = 0; i < nums.size(); i++) {
            insert(root, nums[i]);
        }
        
        int maxResult = 0;

        // For each number, find the maximum XOR with any number in the Trie
        for (int i = 0; i < nums.size(); i++) {
            int tmp = findMax(root, nums[i]);
            maxResult = max(tmp, maxResult);
        }

        return maxResult;
    }
};
