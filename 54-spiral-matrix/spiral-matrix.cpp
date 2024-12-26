class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();

    vector<int>ans;
        int startingrow=0;
        int endingcol=n-1;
        int endingrow=m-1;
        int startingcol=0;
        int total_elem=m*n;
    int count=0;

    while(count<total_elem)
    {
        //starting row
        for(int i=startingcol;i<=endingcol && count < total_elem;i++)
        {
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;
        //endling col
        for(int i=startingrow;i<=endingrow && count < total_elem;i++)
        {
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;

        //ending row
        for(int i=endingcol;i>=startingcol && count < total_elem;i--)
        {
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;
        //starting col
        for(int i=endingrow;i>=startingrow && count < total_elem;i--)
        {
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }
 return ans;


    }
   
};