class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>ans;
       if (matrix.empty()) return ans;  // Check for empty matrix
        
        int top = 0, left = 0;
        int down = matrix.size() - 1;
        int right = matrix[0].size() - 1;
       

        while(top<=down && left <=right)
        {
            for(int j=left;j<=right;j++)
            {
                ans.push_back(matrix[top][j]);
            }top++;

            for(int i=top;i<=down;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

        if(top<=down)
        {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[down][i]);

            }
            down--;
        }
        if(left <=right)
        {
            for(int i=down;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        } 
       return ans; 
    }
};