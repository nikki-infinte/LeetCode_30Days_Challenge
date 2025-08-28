class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>umap;

        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                umap[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &a:umap){
            sort(a.second.begin(),a.second.end()); 
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int key = i -j;

                if(key >=0){
                    grid[i][j] = umap[key].back();
                    umap[key].pop_back();
                }else{
                    grid[i][j] = umap[key].front();
                    umap[key].erase(umap[key].begin());
                }
            }
        }
    return grid;
        
    }
};