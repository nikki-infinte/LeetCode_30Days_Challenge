class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {

        for(int i=0;i<nums.size();i++){
            sort(nums[i].rbegin(),nums[i].rend());
        }
       int n = nums.size();
       int m = nums[0].size();
       vector<vector<int>>newMat(m,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newMat[j][i] = nums[i][j];
            }
        }
        int score=0;
        //transform row to col 
        for(int i=0;i<m;i++){
            priority_queue<int>tmp;
            for(int j=0;j<n;j++){
                tmp.push(newMat[i][j]);

            }
            score+=tmp.top();
        }
      return score;
    }
};