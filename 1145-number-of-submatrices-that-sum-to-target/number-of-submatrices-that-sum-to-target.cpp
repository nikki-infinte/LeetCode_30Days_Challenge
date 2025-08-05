class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>rowSum(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum +=matrix[i][j];
                rowSum[i][j] = sum;
            }

        }
        int ans =0;
         for(int sc =0;sc<m;sc++){
            for(int ec = sc;ec <m;ec++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;


                for(int r =0;r <n;r++){
                    int curr = rowSum[r][ec];
                     if (sc > 0) curr -= rowSum[r][sc - 1];

                    sum += curr;

                    if (mp.find(sum - target) != mp.end()) {
                        ans += mp[sum - target];
                    }

                    mp[sum]++;

                }
            }
         }

         return ans;
    }
};