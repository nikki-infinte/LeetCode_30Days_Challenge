class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        

        priority_queue< pair<int,int> > maxheap;
        int n =nums1.size();
        sort(nums1.begin() , nums1.end());
        int small =0,big = n - 1;

        for(int i=0;i<nums2.size();i++){
            maxheap.push({nums2[i],i});
        }

        vector<int>ans(n,0);
        while(!maxheap.empty()){
            pair<int,int> pq = maxheap.top();
            maxheap.pop();

            if(nums1[big] > pq.first){
                ans[pq.second] = nums1[big];
                big--;
            }else{
                ans[pq.second] = nums1[small];
                small++;
            }

        }
        return ans;

    }
};