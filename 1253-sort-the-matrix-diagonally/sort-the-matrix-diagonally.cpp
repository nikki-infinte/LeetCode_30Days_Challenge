class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        unordered_map<int,vector<int>>umap;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                umap[i-j].push_back(mat[i][j]);
                sort(umap[i-j].begin(),umap[i-j].end());
            }
        }

       
        for(int i=n-1 ; i>=0;i--){
            for(int j=m-1 ; j >=0 ;j--)
            {
                mat[i][j] = umap[i-j].back();
                umap[i-j].pop_back();
            }
        }

        return mat;

    }
};