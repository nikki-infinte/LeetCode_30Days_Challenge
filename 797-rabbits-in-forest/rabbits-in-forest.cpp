class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int>umap;
        for(auto a:answers)
        {
            umap[a]++;
        }

        int total=0;
        for(auto &it:umap)
        {
            int x = it.first;
            int count = it.second;

            int group_Size = x+1;
            int total_g = ceil((double)count/group_Size);
            total+=(total_g * group_Size);
        }
        return total;
    }
};