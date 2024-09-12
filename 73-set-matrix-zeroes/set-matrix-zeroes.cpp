class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         vector<pair<int,int>>vec;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    vec.push_back({i,j});
                }
            }
        }

      for(int i=0;i<vec.size();i++)
      {
        int row=vec[i].first;
        int col=vec[i].second;
        for(int j=0;j<matrix[0].size();j++)
        {
            matrix[row][j]=0;
        }

        for(int j=0;j<matrix.size();j++)
        {
            matrix[j][col]=0;
        }
      }
     
    }
};