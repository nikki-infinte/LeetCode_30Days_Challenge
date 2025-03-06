class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {


     //  brute force : flaten then array and sort    
    
     int n = grid.size();
      vector<int>arr;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
        {
            arr.push_back(grid[i][j]);
        }
     }

     sort(arr.begin(),arr.end());

     int mis =-1,rep =-1;
     for(int i=0;i < arr.size()-1 ;i++ )
     {
        while(arr[i] == arr[i+1])
        {
            rep = arr[i];
            arr.erase(arr.begin()+i);
            if( i!= 0)i--;
        }
     }

     for(int i=0;i<arr.size();i++)
     {
        if(arr[i] != i+1 && mis==-1)mis = i+1;
     }

     if(mis == -1)
     {
        mis = n*n;
     }
     return {rep,mis};
    }
};