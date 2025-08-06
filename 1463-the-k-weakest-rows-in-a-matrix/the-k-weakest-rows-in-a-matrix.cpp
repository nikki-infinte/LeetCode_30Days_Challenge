class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>>pq;
        int n = mat.size();
        for(int i=0;i<n;i++){
            int total = accumulate(mat[i].begin(),mat[i].end(),0);
            pq.push({total,i});

            while(pq.size() > k){
                pq.pop();
            }

        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};