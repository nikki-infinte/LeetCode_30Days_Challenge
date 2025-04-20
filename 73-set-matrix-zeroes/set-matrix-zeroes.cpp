class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       queue<pair<int,int>>q;

       int n=matrix.size();
       int m = matrix[0].size();

       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j] == 0)
            {
                q.push({i,j});
            }
        }
       } 


       while(!q.empty())
       {
        auto p =q.front();
        q.pop();
        
        int x = p.first;
        int y= p.second;
        
            for(int i=0;i<n;i++)
            {
                //colum wise
                matrix[i][y]=0;
            }
            for(int i=0;i<m;i++)
            {
                //row wise
                matrix[x][i] =0;
            }


       }
    }
};