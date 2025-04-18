class Solution {
public:
bool prefer(unordered_map<int, vector<int>>& umap, int person, int current, int candidate) {
    // Returns true if person prefers candidate over current
    for (int p : umap[person]) {
        if (p == candidate) return true;
        if (p == current) return false;
    }
    return false; // default, though shouldn't reach here
}

    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        set<int>unhappy;

        unordered_map<int,vector<int>>umap;
        for(int i=0;i<n;i++)
        {
            umap[i]=preferences[i];
        }
      for(int i=0;i<pairs.size();i++)
{
    int x = pairs[i][0];
    int y = pairs[i][1];

    for(int j=0;j<pairs.size();j++)
    {
        if(i == j) continue;
        int u = pairs[j][0];
        int v = pairs[j][1];

        if(prefer(umap, x, y, u) && prefer(umap, u, v, x)) {
            unhappy.insert(x);
        }
        if(prefer(umap, x, y, v) && prefer(umap, v, u, x)) {
            unhappy.insert(x);
        }
        if(prefer(umap, y, x, u) && prefer(umap, u, v, y)) {
            unhappy.insert(y);
        }
        if(prefer(umap, y, x, v) && prefer(umap, v, u, y)) {
            unhappy.insert(y);
        }
    }
}
return unhappy.size();
      
    }
};