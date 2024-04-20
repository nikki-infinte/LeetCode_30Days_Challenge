class Solution {
public:
    vector<vector<int>>output;
    bool isValid(int n,int m,int i,int j,vector<vector<int>>& land)
    {
           if (i >= 0 && i < n && j >= 0 && j < m && land[i][j] == 1) {
                return true;
            }
            else{
                return false;
            }
    }
    void DFS(int n,int m,int i,int j,vector<vector<int>>& land,int& minRow, int& maxRow, int& minCol, int& maxCol)
    {

        minRow = min(minRow, i);
        maxRow = max(maxRow, i);
        minCol = min(minCol, j);
        maxCol = max(maxCol, j);
        
        land[i][j] = 0; // Mark cell as visited
        
        // Explore neighboring cells
        if (isValid(n, m, i + 1, j, land)) DFS(n, m, i + 1, j, land, minRow, maxRow, minCol, maxCol);
        if (isValid(n, m, i - 1, j, land)) DFS(n, m, i - 1, j, land, minRow, maxRow, minCol, maxCol);
        if (isValid(n, m, i, j + 1, land)) DFS(n, m, i, j + 1, land, minRow, maxRow, minCol, maxCol);
        if (isValid(n, m, i, j - 1, land)) DFS(n, m, i, j - 1, land, minRow, maxRow, minCol, maxCol);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();

    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1)
                {
                     int minRow = i, maxRow = i, minCol = j, maxCol = j;
                     DFS(n, m, i, j, land, minRow, maxRow, minCol, maxCol);
                    output.push_back({minRow, minCol, maxRow, maxCol});

                }
            }
        }
        return output;
    }
};