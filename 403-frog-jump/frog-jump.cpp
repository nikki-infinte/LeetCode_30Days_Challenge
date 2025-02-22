class Solution {
public:
    unordered_map<int,int>umap;
    unordered_map<string, bool> dp; // Memoization
    bool find(int csi,int pj,vector<int>&stones)
    {
        if (csi == stones.size() - 1) return true; // If we reach last stone

    string key = to_string(csi) + "_" + to_string(pj);
    if (dp.find(key) != dp.end()) return dp[key]; // Memoization check

    int nextStoneValue = stones[csi] + pj;
    if (umap.find(nextStoneValue) == umap.end()) return dp[key] = false; // No stone at next position

    int nextIndex = umap[nextStoneValue];

    // Try three possible jumps: k-1, k, k+1
    bool k = find(nextIndex, pj, stones);
    bool k_plus = find(nextIndex, pj + 1, stones);
    bool k_sub = (pj > 1) ? find(nextIndex, pj - 1, stones) : false;

    return dp[key] = k || k_plus || k_sub;
        
        
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        int i=0;
        for(auto a:stones)
        {
            umap[a]=i;
            i++;
        }
        return find(0,1,stones);
    }
};