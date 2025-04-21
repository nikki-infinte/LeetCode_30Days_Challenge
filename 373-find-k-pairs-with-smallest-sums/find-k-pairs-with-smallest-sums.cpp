class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();
        int m =nums2.size();

        priority_queue<P,vector<P>,greater<P>>pq;

        for(int i=0 ; i < k && i <n;i++)
        {
            int sum = nums1[i]+nums2[0];
            pq.push({sum,{i,0}});
        }
        vector<vector<int>>ans;
        while( k-->0 )
        {
            P queueTop = pq.top();
            int i=queueTop.second.first;
            int j=queueTop.second.second;
            pq.pop();

            vector<int>tmp(2,0);
            tmp[0] = nums1[i];
            tmp[1] = nums2[j];

            ans.push_back(tmp);

            if(j+1 < m)
            {
                int sum = nums1[i]+nums2[j+1];
                pq.push({sum,{i,j+1}});
            }


        }
        return ans;

    }
};