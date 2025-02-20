class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int>min_heap;
        int n=mat.size();
  for(int i=0;i < n;i++)
  {
      for(int j=0;j<n;j++)
      {
         min_heap.push(mat[i][j]);
         while(min_heap.size() > k)
         {
             min_heap.pop();
         }
      }
  }
  
  return min_heap.top();
    }
};