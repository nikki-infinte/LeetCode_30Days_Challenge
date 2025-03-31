class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        

        int top =0,left=0;
        int bottom = matrix.size()-1;
        int right=matrix[0].size()-1;
        vector<int>ans;
        while(left <= right && top<=bottom)
        {
            
            //go left to right

            for(int i=left;i<=right;i++)
            {
             ans.push_back(matrix[top][i]);   
            }
            top++;

            // top to bottom
            for(int k = top ;k<=bottom ;k++)
            {
                ans.push_back(matrix[k][right]);
            }
            right--;

            //right to left
            if(top<=bottom){
                for(int p=right;p>=left;p--)
                {
                    ans.push_back(matrix[bottom][p]);
                }
                bottom--;
            }

            if(left <= right){
                for(int k = bottom ; k >= top ;k--)
                {
                    ans.push_back(matrix[k][left]);
                }
                left ++;
            }
        }
        return ans;
    }
};